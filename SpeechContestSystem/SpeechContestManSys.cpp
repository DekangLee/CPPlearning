#include <iostream>
#include "SpeechManager.h"
using namespace std;

int main()
{
    SpeechManager speechManager;
    // print(speechManager.m_Speaker);
    while (true)
    {
        speechManager.Showmenu();
        int choice;
        cout<<"清输入选择：";
        cin >> choice;
        switch (choice)
        {
        case 0: // 0.退出比赛程序
            speechManager.exitSystem();
            break;
        case 1: // 1.开始演讲比赛
            speechManager.startSpeech();
            break;
        case 2: // 2.查看往届记录
            speechManager.loadRecord();
            break;
        case 3: // 3.清空比赛记录
            speechManager.clearRecord();
            break;

        default:
            system("cls");
            break;
        }
         system("cls");
    }
    return 0;
}