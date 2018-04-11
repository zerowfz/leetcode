#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isMatch(string s,string p,int i,int j,vector<int>& mem){
    int key = i*(p.size()+1)+j;
    cout<<key<<" "<<i<<" "<<j<<endl;
    if (mem[key]==-1){
        int ans=0;
	if(j==p.size()) {ans = i==s.size();cout<<"this is 1"<<ans<<endl;}
	else if (i!=s.size()&&(s[i]==p[j]||p[j]=='?')){cout<<"this is 2"<<endl;ans = isMatch(s,p,i+1,j+1,mem);}
	else if (i==s.size()&&p[j]=='*'){cout<<"this is 3"<<endl;ans=isMatch(s,p,i,j+1,mem);}
	else if(p[j]=='*'){cout<<"this is 4"<<endl;ans = isMatch(s,p,i,j+1,mem)+isMatch(s,p,i+1,j,mem);}

	mem[key]=ans;
    } 
    return mem[key];
}
int main()
{
	/*
  string s{"aaa"};
  string b{"*"};
  cout<<isMatch(s,b);
  string c{""};
  cout<<c.substr(1);*/
  string p{"*"};
  string s{"aa"};
  int size = s.size()==0?p.size():s.size()*p.size();
  vector<int> mem((p.size()+1)*(s.size()+1),-1);
  cout<<isMatch(s,p,0,0,mem);
  cout<<endl;
  //vector<int> mem(10,1);
  for (auto i:mem)cout<<i<<" ";
}
