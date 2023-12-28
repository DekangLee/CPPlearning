// #include<iostream>
// #include<string>
// using namespace std;
// char &get_val(string &str,int i)//返回类型为引用
// {//若去掉返回值的引用，则返回的是一个无名变量，其值是返回内容的一个拷贝而已，见下一个程序。
// 	return str[i];
// }
// char get_val1(string &str, int i)
// {
// 	return str[i];

// }
// int main()
// {
// 	string s("123456");
// 	cout<<s<<endl;
// 	get_val(s,2)='a';	//即等价于：str[2]='a'，因为get_val(s,2)返回的是引用，故相当于str[2]
// 	cout<<s<<endl;
// 	cout<<get_val1(s,2)<<endl;
//     system("pause");
// 	return 0;
// }