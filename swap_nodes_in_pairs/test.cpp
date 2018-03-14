#include <iostream>
#include <vector>
using namespace std;
struct node{
    int val;
    node *next;
    node(int x):val(x),next(nullptr){}
};

node* swap(node* head){
    node* p = head;
    int t=0;
    if(!p)return head;
    while(p->next!=nullptr&&(t++)%2==0){
        int tmp = p->val;
	p->val = p->next->val;
	p = p->next;
	p->val = tmp;
	cout<<t<<endl;
    }
    cout<<t<<endl;
    return head;
}
int main()
{
    node* head = new node(1);
    node* p = head;
    p->next = new node(2);
    p = p->next;
    p->next = new node(3);
    p = p->next;
    p->next = new node(4);
    swap(head);
    vector<int> a;
    cout<<a.size();
}
