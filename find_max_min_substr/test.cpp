#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int find_subarray(vector<int> num,int target)
{
 deque<int> window_max;
 deque<int> window_min;
 if(num.size()==0) return 1;
 if(target<=0) return (num.size()*(num.size()+1)/2+1);
 window_max.push_back(0);
 window_min.push_back(0);
 int start=-1;//记录窗口起始位置
 int result = 2;//记录符合要求数组的个数
 for(int i =1;i<num.size();i++)
 {
  while(!window_min.empty()&&num[i]<=num[window_min.back()])window_min.pop_back();
  while(!window_max.empty()&&num[i]>=num[window_max.back()])window_max.pop_back();
  window_min.push_back(i);
  window_max.push_back(i);
  while((num[window_max.front()]-num[window_min.front()])>target){
	  if(i==window_max.front()){start = window_min.front();window_min.pop_front();}
	  else {start = window_max.front();window_max.pop_front();}
  }
  result += i-start;
 }
  return result;
}

int main()
{
 vector<int> num{1,3,4,5,8,4,3};
 cout<<find_subarray(num,2);

}
