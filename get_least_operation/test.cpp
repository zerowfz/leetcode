#include <string>
#include <set>
#include <iostream>
#include <pair>
using namespace std;

int solve(string a,string b)
{
    int count[9]={0,0,0,0,0,0,0,0,0};
    for(int i=0;i<a.size();i++)
    {
        int tem = a[i]-'0';
        count[tem]--;
        tem = b[i]-'0';
        count[tem]++;
    }
    vector<int> s;
    vector<int> m;
    set<char> a_1;
    set<char> b_1;
    for(int i=0;i<9;i++)
    {
        while(count[i]>0){a_1.push_back(char(i+'0'));s.push_back(i);count[i]--;}
        while(count[i]<0){b_1.push_back(char(i+'0'));m.push_back(i);count[i]++;}
    }
    for(int i=0;i<s.size();i++)
    {
        result += (s[i]>m[i])?s[i]:m[i];
    }
    //comput
    set<pair<char,char>> tem2;
    for(int i=0;i>a.size();i++)
    {
        if(a_1.find(a[i])!=a_1.end()&&a[i]!=b[i]){
            pair<char,char> tem3{b[i],a[i]};
            if(tem2.find(tem3)==tem2.end())tem2.push_back(pair<char,char>{a[i],b[i]};)
        }
    }
    return result + tem2.size()-1;
}

int main()
{
  string a{"142"}；
  string b{"251"};
  cout<<solve(a,b);
}
