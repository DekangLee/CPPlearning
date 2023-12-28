// #include <iostream>
// #include <string>
// using namespace std;
// class Lambda
// {
// public:
//     void sayHello()
//     {
//         std::cout << "Hello" << std::endl;
//     };

//     int lambda()
//     {
//         auto function = [this]
//         {
//             this->sayHello();
//             this->set(30);
//             return this->get();
//         };

//        return function();
//     }
//     int get()
//     {
//         return m_a;
//     }
//     void set(int a)
//     {
//         m_a = a;
//     }

// private:
//     int m_a = 10;
// };
// void test01()
// {
//     Lambda L1;
//     cout<<L1.lambda()<<endl;
//     cout<<L1.get()<<endl;
// }
// int main()
// {
//     // test01();
//     // test02();
//     []() throw() { throw 5; }();
//     system("pause");
//     return 0;
// }