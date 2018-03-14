/*
 * 这个算法主要解决的是，给定一个数组，和一个窗口大小，窗口从左到右滑动，返回每一个窗口的最大值。
 * 如array=[1,2,3,4,5,7,5,2] window_size = 3 
 * 返回： [3,4,5,7,7,7]
 *
 *
 * 总结：这个问题的核心在于，我们需要的保留的值，是那些当前时刻的值或者此时最大的值。其他的值都不要考虑。
 * 只有这两个是有可能成为最终的解的。
 * */
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

vector<int> maxInWindows(vector<int> array,int window_size){
    if(window_size==1)return array;
    vector<int> result;
    deque<int> Q{0};
    for(int i=0;i<array.size();i++)
    {
        if(array[i]>=array[Q.front()]){
	    Q.clear();
	}
	else while(array[i]>=array[Q.back()])Q.pop_back();
	while(i>window_size-1&&Q.front()<=i-window_size)Q.pop_front();
	Q.push_back(i);
	if(i>=window_size-1)result.push_back(array[Q.front()]);
    }
    return result;
}

int main()
{
 vector<int> num{2,3,4,2,6,2,5,1};
 vector<int> result = maxInWindows(num,3);
 for(auto iter=result.begin();iter!=result.end();iter++){
     cout<<*iter<<endl;
 }
}
