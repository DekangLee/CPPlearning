// #include <iostream>
// #include <string>
// #include <time.h>
// using namespace std;
// // 分别用普通方法和多态实现四则运算
// // 普通方法
// class Caculator
// {
// public:
//     int m_A;
//     int m_B;
//     Caculator(int a, int b) : m_A(10), m_B(10)
//     {
//         m_A = a;
//         m_B = b;
//     }
//     int getResult(string oper)
//     {
//         if (oper == "+")
//         {
//             return m_A + m_B;
//         }
//         else if (oper == "-")
//         {
//             return m_A - m_B;
//         }
//         else if (oper == "*")
//         {
//             return m_A * m_B;
//         }
//         else // 每次增加新的功能都需要改动源码
//              // 真正的开发中要遵守开闭原则，对扩展功能开放，对修改功能关闭
//         {
//             cout << "输入符号有误" << endl;
//             return 0;
//         }
//     }
// };
// // 使用多态实现计算器
// // 实现计算器抽象类
// class AbstractCaculator
// {
// public:
//     int m_Num1;
//     int m_Num2;
//     virtual int getResult()
//     {
//         return 0;
//     }
// };
// class AddCaculator : public AbstractCaculator
// {
//     int getResult()
//     {
//         return m_Num1 + m_Num2;
//     }
// };
// class SubCaculator : public AbstractCaculator
// {
//     int getResult()
//     {
//         return m_Num1 - m_Num2;
//     }
// };
// class MulCaculator : public AbstractCaculator
// {
//     int getResult()
//     {
//         return m_Num1 * m_Num2;
//     }
// };
// // 多态的好处
// // 1、代码结构清晰
// // 2、代码可读性强
// // 3、对后期扩展和维护友好
// void test01()
// {
//     Caculator caculator(10, 10);
//     cout << "A + B = " << caculator.getResult("+") << endl;
//     cout << "A - B = " << caculator.getResult("-") << endl;
//     cout << "A * B = " << caculator.getResult("*") << endl;
//     cout << "A / B = " << caculator.getResult("/") << endl;
// }
// void test02()
// {
//     AbstractCaculator *abc = new AddCaculator;
//     abc->m_Num1 = 10;
//     abc->m_Num2 = 10;
//     cout << "A + B = " << abc->getResult() << endl;
//     delete abc;
//     abc = new SubCaculator;
//     abc->m_Num1 = 10;
//     abc->m_Num2 = 10;
//     cout << "A - B = " << abc->getResult() << endl;
//     delete abc;
//     abc = new MulCaculator;
//     abc->m_Num1 = 10;
//     abc->m_Num2 = 10;
//     cout << "A * B = " << abc->getResult() << endl;

// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     // test01();
//     test02();
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行时间：" << Times << "s" << endl;
//     system("pause");

//     return 1;
// }