#include <iostream>
using namespace std;

int function(int n,int k){
    if(n==2)return k*(k-1);
    int tem=k;
    for(int i=0;i<n-1;i++){
        tem *=k-1;
    }
    return tem-function(n-1,k);
}
int main()
{   
    int  n,k;
    while(1){
    cin>>n>>k;
    if(n==1)cout<< k<<endl;
    else cout<<function(n,k)<<endl;
    //cout<<function(5,5);
    }
}
