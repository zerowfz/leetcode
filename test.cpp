#include "iostream"
using namespace std;
class MyCalendarTwo {
public:
    MyCalendarTwo():booked{0},n(0),overlap{0},m(0){
        
    }
    
    bool book(int start, int end) {
        if (start>=end)return false;
	int m_=m;//¿¿¿¿¿m¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
        for (int i=0;i<n;i++)
        {
            if(intersect(booked[2*i],booked[2*i+1],start,end))
            {
                //µÃµ½ÖØµş²¿·Ö
             int tem1 = (booked[2*i]>start) ?booked[2*i]:start;
             int tem2 = (booked[2*i+1]>end)?end:booked[2*i+1];
                //ÅĞ¶ÏÖØµş²¿·ÖÊÇ·ñÔÙ´ÎÖØµş
             for (int j=0;j<m;j++)
                 if(intersect(overlap[2*j],overlap[2*j+1],tem1,tem2))
                     return false;
             overlap[2*m] = tem1;
             overlap[2*m+1] = tem2;
	     cout<<tem1<<" "<<tem2<<endl;
             m++;
            }
        }
        booked[2*n]=start;
        booked[2*n+1]=end;
        n++;
        return true;               
    }
private:
    int booked[2000];
    int n;//n¶ÔÓ¦bookedÔªËØ¸öÊı
    int overlap[2000];
    int m;
    inline bool intersect(int a,int b,int c,int d){
        //a,b¶ÔÓ¦Ò»¸öbookedÔªËØµÄÖµ£¬c,d¶ÔÓ¦bookÔªËØµÄÖµ
        if (c>=b||d<=a)return false;
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
int main()
{
 MyCalendarTwo a;
 bool param_1 = a.book(36,41);
 bool param_2 = a.book(28,34);
 bool param_3 = a.book(40,46);
 bool param_4 = a.book(10,18);
 bool param_5 = a.book(4,11);
 bool param_6 = a.book(25,34);
 bool param_7 = a.book(36,44);
 bool param_8 = a.book(32,40);
 bool param_9 = a.book(34,39);
 bool param_10 = a.book(40,49);
}
