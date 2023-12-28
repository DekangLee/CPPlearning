#include "SpeechManager.h"
SpeechManager::SpeechManager()
{
    this->initSystem();
    this->createSpeaker();
}
bool SpeechManager::compare::operator()(const PAIR &p1, const PAIR &p2)
{
    if (p1.second.m_score[1] > p2.second.m_score[1])
    {
        return true;
    }
    else if (p1.second.m_score[1] == p2.second.m_score[1])
    {
        if (p1.second.m_score[0] > p2.second.m_score[0])
        {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
SpeechManager::~SpeechManager()
{
}
void SpeechManager::Showmenu()
{

    cout << "******************************************" << endl;
    cout << "***********  欢迎参加演讲比赛  ***********" << endl;
    cout << "************* 0.退出比赛程序 *************" << endl;
    cout << "************* 1.开始演讲比赛 *************" << endl;
    cout << "************* 2.查看往届记录 *************" << endl;
    cout << "************* 3.清空比赛记录 *************" << endl;
    cout << "******************************************" << endl;
    cout << endl;
}
void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
void SpeechManager::initSystem()
{
    this->v1.clear();
    this->v2.clear();
    this->sVictory.clear();
    this->m_Speaker.clear();
    this->m_Turn = 0;
}
void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; i++)
    {
        string name = "选手";
        name += nameSeed.at(i);
        this->v1.push_back(1001 + i);
        this->m_Speaker.insert(make_pair(v1[i], Speaker(name)));
    }
}
ostream &operator<<(ostream &cout, Speaker &sp)
{
    cout << sp.m_name << " score1:" << sp.m_score[0] << " score2:" << sp.m_score[1];
    return cout;
}
double SpeechManager::geneScore()
{
    deque<double> d_score;
    for (int i = 0; i < 10; i++)
    {
        double score = (rand() % 401 + 600) / 10.f;
        // cout << score << " ";
        d_score.push_back(score);
    }
    sort(d_score.begin(), d_score.end(), greater<double>());
    d_score.pop_front();
    d_score.pop_back();
    double sum = accumulate(d_score.begin(), d_score.end(), 0.0);
    double avg = sum / d_score.size();
    return avg;
}
void SpeechManager::speechDraw()
{
    cout << "第《" << this->m_Turn << "》轮比赛正在抽签---------" << endl;
    cout << "抽签结果如下：" << endl;
    auto _fprint = [&](int num)
    {
        cout << this->m_Speaker[num].m_name << " ";
    };
    if (this->m_Turn == 1)
    {
        random_shuffle(this->v1.begin(), this->v1.end());
        cout << "第一轮，第一组:" << endl;
        for_each(this->v1.begin(), this->v1.end() - 6, _fprint);
        cout << endl;
        cout << "第一轮，第二组:" << endl;
        for_each(this->v1.begin() + 6, this->v1.end(), _fprint);
        cout << endl;
    }
    else
    {
        random_shuffle(this->v2.begin(), this->v2.end());
        cout << "第二轮选手顺序:" << endl;
        for_each(this->v2.begin(), this->v2.end(), _fprint);
        cout << endl;
    }
}
void SpeechManager::speechConstest()
{
    cout << "----------------第《" << this->m_Turn << "》轮比赛正式开始！----------------" << endl;
    multimap<double, int, greater<double>> m_temp;
    vector<int> *v_current;
    vector<int> *v_next;
    int num = 1;
    if (this->m_Turn == 1)
    {
        v_current = &this->v1;
        v_next = &this->v2;
    }
    else
    {
        v_current = &this->v2;
        v_next = &this->sVictory;
    }
    for (auto it = (*v_current).begin(); it != (*v_current).end(); it++)
    {
        double score = this->geneScore();
        // cout<<"score"<<score<<endl;
        this->m_Speaker[*it].m_score[this->m_Turn - 1] = score;
        m_temp.insert(make_pair(score, *it));
        if (num == 6 || num == 12)
        {
            cout << "第" << num / 6 << "组名次：" << endl;
            int count = 0;
            for (auto it : m_temp)
            {
                cout << "number:" << it.second << " name:" << this->m_Speaker[it.second].m_name << " score:"
                     << this->m_Speaker[it.second].m_score[this->m_Turn - 1] << endl;
                if (count < 3)
                {
                    (*v_next).push_back(it.second);
                }
                count++;
            }
            m_temp.clear();
        }
        num++;
    }
    cout << "----------------第《" << this->m_Turn << "》轮比赛结束！----------------" << endl;
}
void SpeechManager::showScore()
{
    cout << "--------------------晋级结果如下-------------------" << endl;
    vector<int> v;
    if (this->m_Turn == 1)
    {
        v = this->v2;
    }
    else
    {
        v = this->sVictory;
    }
    for (auto elem : v)
    {
        cout << "number:" << elem << " name:" << this->m_Speaker[elem].m_name << " score:"
             << this->m_Speaker[elem].m_score[this->m_Turn - 1] << endl;
    }
}
void SpeechManager::saveRecord(ofstream &ofs)
{
    for (auto it : this->sVictory)
    {
        ofs << it << "," << this->m_Speaker[it].m_name << "," << this->m_Speaker[it].m_score[this->m_Turn - 1] << "," << endl;
    }
    ofs << "--"
        << ","
        << "--"
        << ","
        << "--"
        << "," << endl;
}
void SpeechManager::renew()
{
    ofstream ofs;

    ofs.open("speechRecord.csv", ios::out);
    ofs << "number"
        << ","
        << "name"
        << ","
        << "score1"
        << ","
        << "score2" << endl;

    vector<PAIR> v(this->m_Speaker.begin(), this->m_Speaker.end());
    sort(v.begin(), v.end(), compare());
    for (auto it : v)
    {
        ofs << it.first << "," << it.second.m_name << "," << it.second.m_score[0] << "," << it.second.m_score[1] << endl;
    }
    ofs.close();
}
void SpeechManager::startSpeech()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out | ios::app);
    // ofs << "number"
    //     << ","
    //     << "name"
    //     << ","
    //     // << "score" << endl;
    srand(int(time(0)));
    for (int i = 1; i <= 2; i++)
    {
        this->m_Turn = i;
        this->speechDraw();
        this->speechConstest();
        this->showScore();
        system("pause");
    }
    this->saveRecord(ofs);
    ofs.close();
    this->renew();
    this->initSystem();
    this->createSpeaker();
}
void SpeechManager::loadRecord()
{
    map<int, vector<string>> m_record;
    int mycount = 1;
    ifstream ifs(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->Is_empty = true;
        ifs.close();
        system("pause");
        return;
    }
    char ch;
    ifs >> ch;
    if (ch == EOF)
    {
        ifs.close();
        this->Is_empty = true;
        cout << "文件内容为空" << endl;
        system("pause");
        return;
    }
    ifs.putback(ch);
    string buff;
    vector<string> v_str;
    while (ifs >> buff)
    {
        int pos = -1;
        int start = 0;
        string temp;
        // cout << "buff = " << buff << endl;
        while (true)
        {
            pos = buff.find(',', start);
            if (pos == -1)
            {
                // cout<<pos<<endl;
                break;
            }
            temp = temp + buff.substr(start, pos - start) + " ";
            if (temp == "-- ")
            {
                m_record.insert(make_pair(mycount, v_str));
                mycount++;
                break;
            }
            start = pos + 1;
        }
        if (temp == "-- ")
        {
            v_str.clear();
            continue;
        }
        v_str.push_back(temp);
    }
    // cout<<"count = "<<mycount<<endl;
    // cout << m_record[1].size() << endl; // 注意map[key]直接会创建一个新的键值对！！！！
    for (auto record : m_record)
    {
        // cout<<"size =  "<<record.second.size()<<endl;
        cout << "第" << record.first << "界比赛成绩：" << endl;
        for (auto v_str : record.second)
        {
            cout << v_str << endl;
        }
    }
    ifs.close();
    system("pause");
}
void SpeechManager::clearRecord()
{
    cout << "是否清空文件[Y/N]:";
    char ch;
    do
    {
        cin >> ch;
        if (ch != 'Y' && ch != 'N')
        {
            cout << "请重新输入:";
        }
    } while (ch != 'Y' && ch != 'N');
    if (ch == 'Y')
    {
        ofstream ofs1(FILENAME, ios::trunc), ofs2("speechRecord.csv", ios::trunc);
        ofs1.close(), ofs2.close();
        this->initSystem();
        this->createSpeaker();
        cout << "清空成功！" << endl;
    }
    system("pause");
}
void SpeechManager::getPwd()
{
    // char ch;
    // int index = 0;
    // char password[31];
    // while ((ch = _getch()) != '\r')
    // {
    //     if (ch != '\b')
    //     {
    //         printf("*");
    //         password[index++] = ch;
    //     }
    //     else
    //     {
    //         printf("\b \b");
    //         index--;
    //     }
    // }
    // password[index] = '\0';
}
