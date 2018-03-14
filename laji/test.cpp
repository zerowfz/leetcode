#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
 vector<string> str1{"","","abc","def"};
 string a ;
 a.push_back(str1[3][0]);
 string str2 = str1[2];
 for(auto iter = str2.begin();iter!=str2.end();iter++){
     a.push_back(*iter);
 }
 if(str1[0].empty())cout<<"empty"<<endl;
 for(auto iter = str1.begin();iter!=str1.end();iter++)
	 cout<<*iter<<endl;
 for(auto iter2 = a.begin();iter2!=a.end();iter2++)
 cout<<a<<endl;
}
