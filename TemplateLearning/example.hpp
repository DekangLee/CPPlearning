#ifndef __EXZAMPLE__
#define __EXZAMPLE__
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

namespace EXM
{
    template <class T>
    T GenerateNum(int l, int r)
    {
        return l + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (r - l)));
    }
    class Person
    {
    public:
        Person()
        {
        }
        Person(string name, int age, float hight)
        {
            m_Age = age;
            m_Hight = hight;
            m_Name = name;
        }
        Person(const Person &p)
        {
            m_Age = p.m_Age;
            m_Hight = p.m_Hight;
            m_Name = p.m_Name;
        }
        string GetName() const; // 改类函数使用const限定符，意味着任何对象对于该类里的成员属性只能读取，不能修改
        int GetAge() const;
        float GetHight() const;
        void SetName(string name);
        void SetAge(int age);
        void SetHight(float hight);
        bool operator>(const Person &p1)
        {
            if (this->m_Age > p1.m_Age)
                return true;
            else
                return false;
        }
        bool operator<(const Person &p1)
        {
            if (this->m_Age < p1.m_Age)
                return true;
            else
                return false;
        }

    private:
        int m_Age = 0;
        string m_Name;
        float m_Hight;
    };
}
int EXM::Person::GetAge() const
{
    return m_Age;
}
string EXM::Person::GetName() const
{
    return m_Name;
}
float EXM::Person::GetHight() const
{
    return m_Hight;
}
void EXM::Person::SetAge(int age)
{
    m_Age = age;
}
void EXM::Person::SetName(string name)
{
    m_Name = name;
}
void EXM::Person::SetHight(float hight)
{
    m_Hight = hight;
}
ostream &operator<<(ostream &cout, const EXM::Person &p) // 如果仅仅是输出的话可以加const关键字
{
    cout << "姓名：" << p.GetName() << " 年龄：" << p.GetAge() << " 身高：" << p.GetHight(); // 但是需要注意的是GetName()，GetAge()，GetHight()必须也要加关键字const
    return cout;
}
template <class T>
class Array
{
    friend ostream &operator<<(ostream &cout, Array<T> &arr)
    {
        for (auto a : arr)
        {
            // cout<<"开始打印";
            cout << a << "M";
        }
        cout << endl;
        return cout;
    }

public:
    Array()
    {
        lenth = 0;
        arr = nullptr;
    }
    Array(const Array &arr1)
    {
        // cout << "拷贝函数的调用" << endl;
        if (this->arr != nullptr)
        {
            delete[] this->arr;
            this->arr = nullptr;
        }
        this->lenth = arr1.lenth;
        arr = new T[this->lenth];
        for (int i = 0; i < this->lenth; i++)
        {
            this->arr[i] = arr1.arr[i];
        }
    }
    ~Array()
    {
        if (arr != nullptr)
        {
            delete[] arr;
            arr = nullptr;
        }
    }
    Array &operator=(const Array &arr1)
    {
        if (this->arr != nullptr)
        {
            delete[] this->arr;
            this->arr = nullptr;
        }
        this->lenth = arr1.lenth;
        arr = new T[this->lenth];
        for (int i = 0; i < this->lenth; i++)
        {
            this->arr[i] = arr1.arr[i];
        }
        return *this;
    }
    T &operator[](int i)
    {
        return this->arr[i];
    }
    void push_back(const T &a)
    {
        // cout << "push_back()" << endl;
        // cout << sizeof(T) << endl;
        T *temp = new T[this->lenth + 1];
        for (int i = 0; i < this->lenth; i++)
        {
            temp[i] = this->arr[i];
        }
        temp[this->lenth] = a;
        delete[] this->arr;
        this->arr = temp;
        this->lenth++;
    }
    void pop_back()
    {
        T *temp = new T[this->lenth - 1];
        for (int i = 0; i < this->lenth - 1; i++)
        {
            temp[i] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = temp;
        this->lenth--;
    }
    void insert(const T &a, int id)
    {
        if (id > lenth)
        {
            T *temp = new T[id];
            for (int i = 0; i < this->lenth; i++)
            {
                temp[i] = this->arr[i];
            }
            T temp0;
            for (int i = this->lenth; i < id - 1; i++)
                temp[i] = temp0;
            temp[id - 1] = a;
            delete[] this->arr;
            this->arr = temp;
            this->lenth = id;
        }
        else
        {
            T *temp = new T[this->lenth + 1];
            for (int i = 0; i < id - 1; i++)
            {
                temp[i] = this->arr[i];
            }
            temp[id - 1] = a;
            for (int i = id; i < this->lenth + 1; i++)
            {
                temp[i] = arr[i - 1];
            }
            delete[] this->arr;
            this->arr = temp;
            this->lenth++;
        }
    }
    void assign(T *begin, T *end)
    {
        int new_lenth = 0;
        T *begin_temp = begin;
        while (begin_temp != end)
        {
            begin_temp++;
            new_lenth++;
        }
        T *temp = new T[new_lenth];
        for (int i = 0; begin < end; begin++, i++)
        {
            temp[i] = *begin;
        }
        if (this->arr != nullptr)
        {
            delete[] this->arr;
            this->arr = nullptr;
        }
        this->arr = temp;
        this->lenth = new_lenth;
    }
    T *begin()
    {
        return this->arr;
    }
    T *end()
    {
        return this->arr + this->lenth;
    }
    int size()
    {
        return this->lenth;
    }
    void print()
    {
        for (int i = 0; i < this->lenth; i++)
            cout << this->arr[i] << endl;
    }

private:
    // T *arr ;
    // int lenth ;
    T *arr = nullptr; // 将成员变量初始化很有必要
    int lenth = 0;
};

template <class T>
void for_each(T *start, T *end, void (*_f)(T &))
{

    for (T *pointer = start; pointer != end; pointer++)
    {
        _f(*pointer);
    }
}
template <class T>
class myArry
{
public:
    myArry()
    {
        m_Size = 0;
        arr = nullptr;
        m_Capacity = 0;
    }
    myArry(int Capacity)
    {
        this->m_Size = 0;
        this->arr = new T[Capacity];
        this->m_Capacity = Capacity;
    }
    myArry(const myArry &mr)
    {
        // cout<<"拷贝构造"<<endl;
        if (this->arr != nullptr)
        {
            delete[] this->arr;
            this->arr = nullptr;
        }
        this->m_Capacity = mr.m_Capacity;
        this->m_Size = mr.m_Size;
        this->arr = new T[this->m_Size];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->arr[i] = mr.arr[i];
        }
    }
    ~myArry()
    {
        if (this->arr != nullptr)
        {
            delete[] this->arr;
            this->arr = nullptr;
        }
    }
    T *begin()
    {
        return this->arr;
    }
    T *end()
    {
        return this->arr + this->m_Size;
    }
    myArry &operator=(const myArry &mr)
    {
        mr.GetCapacity();
        // cout << "=运算符重载" << endl;
        if (this->arr != NULL)
        {
            delete[] this->arr;
            this->arr = nullptr;
        }
        this->m_Capacity = mr.m_Capacity;
        this->m_Size = mr.m_Size;
        this->arr = new T[this->m_Size];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->arr[i] = mr.arr[i];
        }
        return *this;
    }
    T &operator[](int i)
    {
        return *(this->arr + i);
    }
    int GetSize()
    {
        return m_Size;
    }
    int GetCapacity()
    {
        return m_Capacity;
    }
    void push_back(const T &a)
    {
        this->arr[m_Size] = a;
        m_Size++;
        m_Capacity--;
    }
    void remove()
    {
        T *temp = new T[m_Size + m_Capacity];
        for (int i = 0; i < m_Size - 1; i++)
        {
            temp[i] = arr[i];
        }
        m_Size--;
        m_Capacity++;
        delete[] this->arr;
        arr = temp;
        temp = nullptr;
    }
    void print()
    {
        for (int i = 0; i < m_Size; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

private:
    int m_Size = 0;
    T *arr = nullptr;
    int m_Capacity = 0;
};
template <class T>
void print(const T &element) // const 可以防止print函数修改传入的值,需要注意的是当加const后该函数调用所有的element里的方法有需要有const修饰
{
    for (auto a = element.begin(); a != element.end(); a++)
    {
        cout << *a<<endl;
        // *a = 10;  //报错！！只可读取数据
    }
}
// template <class T>
// void print(const T &element)
// {
//     for (auto a : element)
//     {
//         cout << a<<endl;
//     }
//     cout << endl;
// }
template <class T>
void printf(T element)
{
    cout << element << endl;
}
#endif