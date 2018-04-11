#include <string>
#include <iostream>
#include <vector>
using namespace std;
void func(string s,int n,int left,int right,vector<string>& result)
{
    if(s.size()==n*2){result.push_back(s);return;}
    if(left<n)func(s+"(",n,left+1,right,result);
    if(right<left)func(s+")",n,left,right+1,result);
}
int main()
{
    vector<string> result;
    func("",3,0,0,result);
    for(auto i:result)cout<<i<<endl;
}
