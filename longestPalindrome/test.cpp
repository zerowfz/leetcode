#include <string>
#include <iostream>
using namespace std;
string longestPalindrome(string s) {
    string x="#";
    //cout<<x;
    const int n = s.size();
    int p[2*n+1]={0};
    for (auto i = s.begin();i!=s.end();++i)
    {
	    x += *i;
	    x += '#';
    }
    int id=0,mx=0,j=1;
    for (auto i= x.begin()+1;i!=x.end();i++)
    {
    p[j] = (mx>j)?(p[2*id-j]>(mx-j)?mx-j:p[2*id-j]):1;
    while(x[j+p[j]]==x[j-p[j]]&&(j-p[j]>=0)&&(j+p[j]<=2*n))p[j]++;
    if(j+p[j]>mx){
    id = j;
    mx = p[j]+j;
    }
    j++;
    }
    int max =0,ce = 0;
    for (int i=0;i<2*n+1;i++)
    {
    //cout<<p[i]<<endl;
    if (p[i]>max){
    ce = i;
    max = p[i];
    }
    }
    cout<<ce-p[ce]+1<<endl;
        return s.substr((ce-p[ce]+1)/2,p[ce]-1);
}
int main()
{
 string s = "babad";
 string t = longestPalindrome(s);
 for (auto i = t.begin();i!=t.end();i++)cout<<*i<<endl;
 int a[3];
 for (int i=0;i<3;i++)cout<<a[i]<<endl;
}
