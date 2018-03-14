#include <iostream>
#include <vector>
using namespace std;

int key(vector<int> a,int i ,int j)
{
 if(i==(j-1)) return i;
 int c = (i+j)/2;
 if(a[c]==1)return key(a,c,j);
 else return key(a,i,c);
}

int answer(vector<int> a){
    if (a[0]==0)return 0;
    if (a[1]==1)return a.size();
    return key(a,0,s.size()-1);
}

int main()
{
    
    vector<int> lis{1,1,1,1,1,1,1,0,0,0,0,0,0,0};
    int c = answer(lis);
    if (c==lis.size())cout<<"未出错";
    else cout<<c;
}
