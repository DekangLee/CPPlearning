// #include <iostream>
// #include <string>
// #include <time.h>
// #include <cstdlib> 
// using namespace std;
// const int MAXSIZE = 10;
// // 实现对通用的数组排序
// // 使用选择排序
// template <class T>
// void mySwap(T &a, T &b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }
// template <class T>
// void mySort(T Arry[], int lenth) // 选择排序
// {
//      // 最大值的下标
//     for (int i = 0; i < lenth; i++)
//     {
//         int max = i;
//         for (int j = i + 1; j < lenth; j++)
//         {
//             if (Arry[j] > Arry[max])
//             {
//                 max = j;
//             }
//         }
//         if (max != i)
//         {
//             mySwap(Arry[max], Arry[i]);
//         }
//     }
// }
// template <class T>
// void PrintArry(T Array[], int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         cout << Array[i] << " ";
//     }
//     cout << endl;
// }
// int part(int* r, int low, int hight)  //划分函数
// {
// 	int i = low, j = hight, pivot = r[low]; //基准元素
// 	while (i < j)
// 	{
// 		while (i<j && r[j]>pivot) //从右向左开始找一个 小于等于 pivot的数值
// 		{
// 			j--;
// 		}
// 		if (i < j)
// 		{
// 			mySwap(r[i++], r[j]);  //r[i]和r[j]交换后 i 向右移动一位
// 		}
// 		while (i < j && r[i] <= pivot) //从左向右开始找一个 大于 pivot的数值
// 		{
// 			i++;
// 		}
// 		if (i < j)
// 		{
// 			mySwap(r[i], r[j--]);  //r[i]和r[j]交换后 i 向左移动一位
// 		}
// 	}
// 	return i;  //返回最终划分完成后基准元素所在的位置
// }
// void Quicksort(int* r, int low, int hight)
// {
// 	int mid;
// 	if (low < hight)
// 	{
// 		mid = part(r, low, hight);  // 返回基准元素位置
// 		Quicksort(r, low, mid - 1); // 左区间递归快速排序
// 		Quicksort(r, mid+1, hight); // 右区间递归快速排序
// 	}
// }
// template <class T> // 快速排序（使用递归调用数据量较大时会造成堆栈溢出）
// void myQSort(T Array[], int start, int end)
// {
//     if (start >= end)
//         return;
//     int i = start;
//     int j = end;
//     // cout<<"end"<<end<<endl;
//     int mid = (i+j)/2;
//     T key = Array[mid];
//     // cout<<"key:"<<key<<endl;
//     while (i < j)
//     {
//         while (mid < j && Array[j] > key)
//         {
//             j--;
//         }
//         swap(Array[mid],Array[j]);
//         // cout<<"j="<<j<<endl;
//         while (i < mid && Array[i] < key)
//         {
//             i++;
//         }
//         swap(Array[mid],Array[i]);
//         // PrintArry(Array, MAXSIZE);
//     }
//     // Array[i] = key;
    
//     myQSort(Array, start, i - 1);
//     myQSort(Array, j + 1, end);
// }

// char add(int a, int b)
// {
//     return a + b;
// }
// template <class T>
// T add(T a, T b)
// {
//     return a + b;
// }
// template <class T>
// void Genetate(T *a,int n,int l,int r)//生成范围在l~r的随机数 
// {
// 	srand(time(0));  //设置时间种子
// 	for(int i=0;i<n;i++){
// 		a[i]=rand()%(r-l+1)+l;//生成区间r~l的随机数 
// 	}
// }
// void test01()
// {
//     char CharArry[] = "asbzncv";
//     int IntArry[MAXSIZE];
//     Genetate(IntArry, MAXSIZE,0,100);
//     PrintArry(IntArry, sizeof(IntArry) / sizeof(int));
//     // myQSort(CharArry, 0, 6);
//     // myQSort(IntArry, 0, MAXSIZE-1);
//     Quicksort(IntArry, 0, MAXSIZE-1);
//     // PrintArry(CharArry, sizeof(CharArry) / sizeof(char));
//     PrintArry(IntArry, sizeof(IntArry) / sizeof(int));
// }
// void test02()
// {
//     int a = 10;
//     char b = 'b';
//     cout << add(a, b) << endl;
//     cout << add(a, b) << endl;
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     test01();
//     // test02();
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行时间：" << Times << "s" << endl;
//     system("pause");

//     return 1;
// }