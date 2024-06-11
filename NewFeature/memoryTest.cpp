/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-06-07 15:47:24
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-06-11 11:07:49
 * @FilePath: \CPPlearning\NewFeature\memoryTest.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <memory>
#include <string>
#include <functional>

// c++11中提供了三种智能指针，分别为
// 1.std::shared_ptr:共享智能指针
// 2.std::unique_ptr:独占智能指针
// 3.std::weak_ptr:若引用智能指针，不共享指针，不能操作资源，用来监视shared_ptr
class TEST
{
public:
    TEST()
    {
        std::cout << "construct default ..." << std ::endl;
    }
    TEST(int num) : m_num(num)
    {
        std::cout << "construct TEST(int num)" << std::endl;
    }
    TEST(std::string str) : m_string(str)
    {
        std::cout << "construct TEST(std::string str)" << std::endl;
    }
    void setValue(int value)
    {
        this->m_num = value;
    }
    inline int getValue()
    {
        return m_num;
    }
    ~TEST()
    {
        std::cout << "destruct ...." << std::endl;
    }
    int m_num = 0;
    std::string m_string;
};
std::unique_ptr<int> fun(int p)
{
    std::unique_ptr<int> ptr(new int(p));
    return ptr;
}
int main()
{
    // 使用shared_ptr智能指针管理一块堆内存
    // std::shared_ptr<int> ptr1(new int(405));
    // std::cout << "ptr1管理内存的引用计数：" << ptr1.use_count() << std::endl;
    // std::shared_ptr<int> ptr2(ptr1);
    // std::cout << "ptr2管理内存的引用计数：" << ptr2.use_count() << std::endl;
    // std::shared_ptr<int> ptr3(ptr2);
    // std::cout << "ptr3管理内存的引用计数：" << ptr3.use_count() << std::endl;
    // std::shared_ptr<int> ptr4(ptr1);
    // std::cout << "ptr4管理内存的引用计数：" << ptr4.use_count() << std::endl;
    // std::shared_ptr<int> ptr5(std::move(ptr1));
    // std::cout << "ptr5管理内存的引用计数：" << ptr5.use_count() << std::endl;
    // std::cout << "ptr1管理内存的引用计数：" << ptr1.use_count() << std::endl;

    // 通过make_share初始化
    // std::shared_ptr<int> ptr1 = std::make_shared<int>(8);
    // std::cout << *ptr1.get() << std::endl;
    // std::shared_ptr<TEST> ptr2 = std::make_shared<TEST>("hello, world"); // 参数会自动匹配构造函数

    // 通过rest初始化
    // ptr2.reset(); // 重置后不在管理任何内存
    // std::cout << ptr2.use_count() << std::endl;
    // ptr1.reset(new int(10));
    // std::cout << "引用计数:" << ptr2.use_count() << " 内存信息:" << *ptr1.get() << std::endl;
    // std::shared_ptr<const char *> ptrC = std::make_shared<const char *>("hello  dekanglee");
    // std::cout << *ptrC.get() << std::endl;

    // 通过ptr2访问内存
    // std::cout << ptr2->getValue() << std::endl;
    // ptr2->setValue(10);
    // 通过临时指针访问内存
    // TEST *temp = ptr2.get();
    // std::cout << temp->getValue() << std::endl;

    // 给shared_ptr指定删除器
    // std::shared_ptr<int> ptr3(new int(100), [](int *value)
    //                           {
    //     // 释放内存
    //     std::cout <<"共享智能指针删除器"<<std::endl;
    //     delete value; });

    // ptr3.reset(); // 引用计数为零的时候调用该函数，会删除指向的内存
    // std::shared_ptr<TEST> ptr4(new TEST[5], [](TEST *t)
    // {
    //     delete[] t;
    // });
    // std::shared_ptr<TEST> ptr4(new TEST[5], std::default_delete<TEST []>());

    // unique_ptr独占智能指针
    // std::unique_ptr<int> ptr1(new int(10));
    // std::unique_ptr<int> ptr2 = ptr1; 错误！
    // unique_ptr(const unique_ptr &) = delete;
    // unique_ptr &operator=(const unique_ptr &) = delete; 源码中将赋值与拷贝构造函数均禁用了
    // std::unique_ptr<int> ptr2 = std::move(ptr1); // 可以！使用移动构造转移所有权
    // std::cout << ptr1.get() << std::endl;
    // int *a = new int;
    // ptr2.get_deleter()(a); // 调用ptr2的删除器
    // std::cout << ptr2.get() << std::endl;
    // std::unique_ptr<int> ptr3 = fun(4);
    // std::cout << *ptr3.get() << std::endl;

    // unique_ptr指定删除器
    // using ptrFunc = void (*)(TEST *);
    // std::unique_ptr<TEST, ptrFunc> ptr4(new TEST("hello"),[](TEST *t){
    //     std::cout << "---------" <<std::endl;
    //     delete t;
    // });
    // std::unique_ptr<TEST, std::function<void(TEST*)> > ptr5(new TEST("hello"),[=](TEST *t){
    //     std::cout << "---------" <<std::endl;
    //     delete t;
    // });

    // 独占智能指针可以管理数组类型地址
    // std::unique_ptr<TEST[]>ptr6(new TEST[5]);
    // c++11里面不支持shared_ptr管理数组
    // std::shared_ptr<TEST[]>ptr7(new TEST[5]);

    // weak_ptr智能指针
    std::shared_ptr<int> sp1, sp2;
    std::weak_ptr<int> wp;
    sp1 = std::make_shared<int>(3);
    wp = sp1;
    sp2 = wp.lock();
    std::cout << "use_count:" << wp.use_count() << std::endl;
    sp1.reset();
    std::cout << "use_count:" << wp.use_count() << std::endl;
    sp1 = wp.lock();
    std::cout << "use_count:" << wp.use_count() << std::endl;

    std::cout << "sp1: "<< *sp1.get()<< std::endl;
    std::cout << "sp2: "<< *sp2.get()<< std::endl;
    return 0;
}