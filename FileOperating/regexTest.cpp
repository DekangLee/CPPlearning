// #include <iostream>
// #include <string>
// #include <vector>
// #include <regex>
// using namespace std;
 
// int regexSplit(string&,const string,vector<string>&,int);
 
// int main(void)
// {
//  	vector <string> vect;
// 	string str = "(12.3e+10-0.018e-5)+(11.006-7.)+.89";
// 	string reg[11]={
// 		"(\\d+)",				/*整数，包括0开头的 */ 
// 		"([1-9]\\d*)",			/*错：整数，但取不到0 */ 
// 		"(0|[1-9]\\d*)",		/*全部整数 */ 
// 		"(\\d+\\.\\d+)",		/*小数不包括整数 */ 
// 		"(\\d*\\.?\\d+)",		/*错：整数或小数，但包括7. */ 
// 		"(\\d+\\.?\\d*)",		/*错：整数或小数，但包括.89 */ 
// 		"(\\d+|\\d+\\.\\d+)",	/*整数或小数 */ 
// 		"-?(\\d+|\\d+\\.\\d+)",	/*正数或负数 */ 
// 		"\\([^()]*\\)",			/*匹配成对的括号 */ 
// 		"-?(\\d+\\.\\d+)e[+-]\\d+",	/*科学记数法 */	
// 		"-?((\\d+|\\d+\\.\\d+)|(\\d+\\.\\d+)e[+-]\\d+)"	/*实数 */
// 		};
// 	cout<<str<<endl<<"--------------"<<endl;
// 	for (auto a:reg){
// 		regexSplit(str,a,vect,0);
// 		cout<<"pattern:"<<a<<endl<<"string: ";
// 		for(auto v:vect) cout<<v<<" ";
// 		vect.clear(); //重要，否则后一次的循环取到的值会累积到vect中。
// 		cout<<endl<<"=============="<<endl;
// 	}
//     system("pause");
// 	return 0;
//  }
 
// int regexSplit(string &str,const string str_reg,vector<string>&vect,int pos)
// {
// 	if (pos!=-1) pos=0;  //pos=0 匹配到的位置，pos=-1匹配位置的前一字串 
// 	regex Pattern(str_reg); 
//     sregex_token_iterator it(str.begin(),str.end(),Pattern, pos); 
//     sregex_token_iterator end;
//     for(;it!=end;it++) vect.push_back(*it); 
//     return vect.size();  //if 0 没有匹配到，else 匹配到的个数
//  } 