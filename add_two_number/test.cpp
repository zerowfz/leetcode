#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};
ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
    ListNode* result = new ListNode(0);
    ListNode *p =result;
    ListNode *q =p;
    auto n1 = l1;
    auto n2 = l2;
    while(n1!=nullptr&&n2!=nullptr){
        int sum = l1->val+l2->val;
        q = p;
        p->val += sum%10;
	p->next = new ListNode(sum/10);
	n1 = n1->next;
	n2 = n2->next;
	p = p->next;
    }
    if(n1==nullptr&&n2==nullptr){
	delete []p;
	//cout<<p->val<<endl;
        p = nullptr;
	q->next = nullptr;
	//cout<<"qwer"<<endl;
    }
    else if(n1==nullptr){
        p->val += n2->val;
	p->next = n2->next;
	cout<<"21"<<endl;
    }else{
        p->val += n1->val;
	p->next = n1->next;
    }
    return result;
}

int main()
{
 ListNode* l1 = new ListNode(3);
 l1->next = new ListNode(2);
 ListNode* l2 = new ListNode(4);
 l2->next = new ListNode(5);
 auto p = addTwoNumbers(l1,l2);
 while(p!=nullptr){
     cout<<p->val<<endl;
     p = p->next;
 }

}
