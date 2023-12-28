#include <iostream>
#include <string>
#include <time.h>
using namespace std;
// 抽象不同的基类
// CPU基类
class CPU
{
public:
    virtual void caculate() = 0;
};
// 显卡基类
class VideoCard
{
public:
    virtual void display() = 0;
};
// 内存条基类
class Memory
{
public:
    virtual void storage() = 0;
};
class Computer
{
public:
    Computer(CPU *cpu, VideoCard *VC, Memory *mem)
    {
        m_cpu = cpu;
        m_VC = VC;
        m_mem = mem;
    }
    // 提供工作函数
    void work()
    {
        m_cpu->caculate();
        m_VC->display();
        m_mem->storage();
    }
    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_VC != NULL)
        {
            delete m_VC;
            m_VC = NULL;
        }
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    CPU *m_cpu;
    VideoCard *m_VC;
    Memory *m_mem;
};
class IntelCPU : public CPU
{
    void caculate()
    {
        cout << "Intel的CPU开始工作了" << endl;
    }
};
class IntelVideoCard : public VideoCard
{
    void display()
    {
        cout << "Intel的显卡开始工作了" << endl;
    }
};
class IntelMemory : public Memory
{
    void storage()
    {
        cout << "Intel的内存条开始工作了" << endl;
    }
};
class HuaweiCPU : public CPU
{
    void caculate()
    {
        cout << "IHuawei的CPU开始工作了" << endl;
    }
};
class HuaweiVideoCard : public VideoCard
{
    void display()
    {
        cout << "IHuawei的显卡开始工作了" << endl;
    }
};
class HuaweiMemory : public Memory
{
    void storage()
    {
        cout << "IHuawei的内存条开始工作了" << endl;
    }
};
void test01()
{
  
    Computer *pc1 = new Computer(new IntelCPU,new IntelVideoCard, new IntelMemory);
    cout<<"第一台电脑开始工作----------------------"<<endl;
    pc1->work();
    delete pc1;
    Computer *pc2 = new Computer( new HuaweiCPU, new HuaweiVideoCard,new HuaweiMemory);
    cout<<"第二台电脑开始工作----------------------"<<endl;
    pc2->work();
    delete pc2;
    Computer *pc3 = new Computer(new HuaweiCPU,new IntelVideoCard, new HuaweiMemory);
    cout<<"第三台电脑开始工作---------------------"<<endl;
    pc3->work();
    delete pc3;
}
int main()
{
    clock_t start_time, end_time;
    start_time = clock(); // 获取开始执行时间
    test01();
    // test02();
    end_time = clock();
    double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "程序运行时间：" << Times << "s" << endl;
    system("pause");

    return 1;
}