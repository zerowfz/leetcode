#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> s{1,1,1,1,1};
    int i=4;
    while(s[i--]==1&&i>0){
        cout<<i<<endl;
    }
    cout<<"finished:"<<i<<endl;
}
