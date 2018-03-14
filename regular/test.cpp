#include <iostream>
#include <map>
#include <string>

using namespace std;
bool dp(string s,string p,int i,int j, map<int,bool> &mem)
{       
	int key = i*(p.size()+1)+j;
	if(mem.find(key)==mem.end())
	{
	bool ans;
	//if(i == s.size()) ans = (j==p.size()||(p[j+1]=='*'&&j==p.size()-2));
	//else if(j == p.size()) ans = i==s.size();
	if (j==p.size()) ans = i==size();//注意这里是唯一的出口，只有当我们要匹配的字符，到最后一个字符才能判断与原始字符是否匹配
	else{
	bool original_match = (i<s.size()&&(s[i]==p[j]||p[j]=='.'));
	if(p[j+1]=='*'){
		ans = dp(s,p,i,j+2,mem) || (original_match && dp(s,p,i+1,j,mem));
	}else ans = (original_match && dp(s,p,i+1,j+1,mem));
	}
	mem[key] = ans;
	}
	return mem[key];
 
}
bool isMatch(string s,string p){
	map<int,bool> mem;
	bool a = dp(s,p,0,0,mem);
	for (auto i=mem.begin();i!=mem.end();i++){
		cout<<i->first<<i->second<<endl;
	}
	return a;
}
int main()
{
 string s("aa");
 string p("a*");
 cout<<isMatch(s,p);
}
