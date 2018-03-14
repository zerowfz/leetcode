#include <vector>
#include <iostream>
using namespace std;
struct node{
    int val;
    node *next;
    node(int x):val(x),next(NULL){};
};
int main()
{
 node* a = new node(0);
 vector<node*> list{nullptr};
 for (auto iter = list.begin();iter!=list.end();){
    if ((*iter)==nullptr)list.erase(iter);
    else iter++;
    cout<<1<<endl;
 }
 //auto iter = list.begin();
 //if(*iter==nullptr)list.erase(iter);
 //cout<<list.size();
 //for (auto iter=list.begin();iter!=list.end();iter++)
 //	 cout<<*iter<<endl;
 //cout<<*(list.begin())<<endl;
 
 //if(list[0]==nullptr)list.pop_back();
 //cout<<list.size();
 //cout<<(*(list.begin()))->val<<endl;
 //list.erase(list.begin());
 //cout<<list.size();
}
