#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <tuple>
using namespace std;


//get all the str

void get_str(string tem,map<int,vector<int>> a_pro,int iter,string a,vector<string>& result){
    if(iter==a.size()){result.push_back(tem);return;}
    int key = a[iter]-'0';
    if(a_pro.find(key)==a_pro.end()){cout<<"a[iter]:"<<a[iter]<<endl;;get_str(tem+a[iter],a_pro,iter+1,a,result);}
    else
    for(int i=0;i<a_pro[key].size();i++){
	    map<int,vector<int>> tem3;
	    tem3=a_pro; 
	    tem3[key].erase(tem3[key].begin()+i);
	    get_str(tem+to_string(a_pro[key][i]),tem3,iter+1,a,result);
    }
}
int get_swap_num(string a,string b){
    map<pair<int,int>,int> tem;
    int result=0;
    for(int i=0;i<a.size();i++){
	if(a[i]==b[i])continue;
	pair<int,int> tem2{b[i]-'0',a[i]-'0'};
        if(tem.find(tem2)!=tem.end()&&tem[tem2]>0){tem[tem2]--;continue;}
	pair<int,int> tem3{a[i]-'0',b[i]-'0'};
	if(tem.find(tem3)==tem.end())tem[tem3]=1;
	else tem[tem3]++;
	result++;
    }
    return result;
}

int solve(string a,string b)
{
    int count[10]={0,0,0,0,0,0,0,0,0,0};//different element count
    int count_a[10]={0,0,0,0,0,0,0,0,0,0};//elements of a count
    int result=0;
    for(int i=0;i<a.size();i++)
    {
        int tem = a[i]-'0';
	count_a[tem]++;
        count[tem]--;
        tem = b[i]-'0';
        count[tem]++;
	
    } 
    vector<int> s;
    vector<int> m;
    for(int i=0;i<10;i++)
    {
        while(count[i]>0){s.push_back(i);count[i]--;}
        while(count[i]<0){m.push_back(i);count[i]++;}
    }
    map<int,vector<int>> a_pro;
    for(int i=0;i<s.size();i++)
    {
	cout<<"s[i]"<<s[i]<<"m[i]"<<m[i]<<endl;
        result += (s[i]>m[i])?s[i]-m[i]:m[i]-s[i];
	if(!a_pro.count(m[i]))a_pro[m[i]]=vector<int>{s[i]};
	else a_pro[m[i]].push_back(s[i]);
    }
    for(auto iter=a_pro.begin();iter!=a_pro.end();iter++)
    {
        while(iter->second.size()<count_a[iter->first])iter->second.push_back(iter->first);
    }
    vector<string> result2;
    get_str("",a_pro,0,a,result2); 
    //comput 
    for(auto i:result2)cout<<i<<endl;
    int min=9;
    for(int i=0;i<result2.size();i++){
        int x = get_swap_num(result2[i],b);
	if(x<min){min = x;cout<<i<<endl;}
    }
    cout<<result<<endl;
    cout<<min<<endl;
    return result + min;
}

int main()
{
  string a{"2299"};
  string b{"1122"};
  cout<<solve(a,b);
}
