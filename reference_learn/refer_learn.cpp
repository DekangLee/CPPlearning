#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
// int a; // 对于未赋初值的全局变量或静态变量值为零
float b;
char c;   // 空格
string s; // 为空
class Person
{
public:
    Person()
    {
        cout << "Person的默认构造" << endl;
    }
    Person(int i)
    {
        cout << "Person的有参构造" << endl;
    }
    Person(const Person &p)
    {
        cout << "Person的拷贝构造" << endl;
    }
    int m_A;
    int m_B;
};
// Person p2;
int arr1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
template <class T>
void PrintArry1D(T Array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}
template <class T>
void PrintArry2D(T (*arr)[4], int row, int colum)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
template <class T>
void PrintArry2D1(T *arr[], int row, int colum)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
template <class T>
void PrintArry2D2(T **arr, int row, int colum)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void pointerArry()
{
    int arr1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    PrintArry2D(arr1, 3, 4);
    // int(*p1)[4] = new int[3][4];  // 开辟堆区内存，用p1指针维护
    int(*p1)[4] = arr1;    // 给二维数组arr1建立了别名p1
    int(&p2)[3][4] = arr1; // 使用引用的方式来给arr1创立别名
    // int p3[3][4] = arr1; //报错！！！！！编译器会认为你在用arr1的值初始化p3栈区数组
    p1[0][0] = 2; // 相当于修改arr1[0][0]
    PrintArry2D(arr1, 3, 4);
    PrintArry2D(p2, 3, 4); // p2也会跟着变
}
void arryPointer()
{
    // int arr1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int *p3[4]; // 使用数组指针引用二维数组
    for (int i = 0; i < 3; i++)
    {
        *(p3 + i) = arr1[i];
    }
    // PrintArry2D(p3, 3, 4);   对于PrintArry2D(T (*arr)[4], int row, int colum)无法传参
    PrintArry2D1(p3, 3, 4);
}
void doublePointer()
{
    // int arr1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int **p2 = new int *[3]; // 必须事先分配内存  否则会导致内存泄漏 事实上此时的双重指针就是数组指针！！！！！
    // int **p2;
    // p2 = arr;  // 报错！！！
    // 使用双重指针引用二维数组
    // int **p2;
    // p2 = arr;  //不能将int*的实体分配到int**
    for (int i = 0; i < 3; i++)
    {
        *(p2 + i) = arr1[i];
    }
    // PrintArry2D(p2,3,4); 报错！！
    // PrintArry2D1(p2, 3, 4); // 可以传参PrintArry2D1(T *arr[], int row, int colum)
    PrintArry2D2(p2, 3, 4); // 可以传参PrintArry2D2(T **arr, int row, int colum)
    delete[] p2;
}
const int &func(const int &a)
{
    return a;
}
Person func(const Person &p)
{
    int a; // 未赋初值的局部变量，由于是栈里分配的内存空间所以数值不确定
    cout << a << endl;
    return p;
} // 如果以值的方式返回，编译器将会拷贝一个临时变量；
void test01()
{

    int b = 10;
    int *const a = &b;
    const int *c = &b;
    *a = 20;
    // a = &a; // a为指针常量，内容为常量不可以修改地址可以修改值
    int d;
    c = &d;
    // *c = 20 ;  // c为常量指针，地址可以修改值不可以修改
    int &l_ref1 = b;
    int &var1 = l_ref1;
    cout << "var1 = " << var1 << endl;
    // l_ref1 = 30;
    cout << "var1 = " << var1 << endl;
    // cout << "a = " << *a << endl;
    // cout << "b = " << b << endl;
    // cout << "c = " << *c << endl;
}
int main()
{
    // float a;
    // cout<<a<<endl;
    // cout << a << " " << b << "" << c << "--" << endl;
    // cout << "----" << s << "----" << endl;
    // Person p1;
    // cout << func(p1).m_A << endl;
    // Person &p2 = p1;
    // cout << p2.m_A << endl;
    // pointerArry();
    // arryPointer();
    // doublePointer();
    // double dha;
    // cout << sizeof(int) << endl;
    // cout << sizeof(short) << endl;
    // cout << sizeof(unsigned int) << endl;
    // cout << sizeof(float) << endl;
    // cout << sizeof(double) << endl;
    // cout<<1/3.0<<endl;
    // test01();
    int a;
    // cin >> a;
    cout<<a<<endl;
    system("pause");
    return 1;
}