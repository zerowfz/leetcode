/*
 *这个问题是计算积水的多少。
 给定一串数组，表示的是高度，问最多的积水的多少。
 例如0,1,0,2,1,0,1,3,2,1,2,1  返回的是6
 * */
#include <stack>
#include <iostream>
#include <vector>

using namespace std;
class solve{
	public:
    solve(vector<int> a):height(a){}
    int brute_force();
    int mem_solve();
    int stack_solve();
    int twopass_solve();
    vector<int> height;
};
int solve::brute_force(){
    /*暴力破解，该问题实际上是对每一个位置，计算它左边和右边的最大高度，两者的最小值减去
     * 该位置的高度，对应的就是这个问题的最大积水量*/
	int result=0;
    for(int i=1;i<height.size()-1;i++){
	int left_max = height[i];
	int right_max = height[i];
        for(int j=i-1;j>=0;j--){
	    if(height[j]>left_max)left_max = height[j];
	}
	for(int j=i+1;j<height.size();j++)
		right_max = right_max>height[j]?right_max:height[j];
	result += (right_max>left_max?left_max:right_max)-height[i];
    }
    return result;
}

int solve::mem_solve(){
    /*可以看出来上面的办法实际上有很多重复的计算，其实对于每一个元素，我们不需要同时去计算leftmax和
     * rightmax，在从左到右的过程中，我们可以得到所有元素的leftmax，从右到左中，我们可以得到所有元素的rightmax,
     * 我们可以把它们记录下来*/
	int tem_max=0;
	int result=0;
	vector<int> left_max(height.size()),right_max(height.size());
    for(int i=0;i<height.size();i++){
	if(height[i]>tem_max)tem_max = height[i];//注意这里的left_max为什么要在后面赋值，这样就能保证，在任何一个位置它的高度都是小于等于leftmax和rightmax的
	left_max[i] = tem_max;
    }
    tem_max=0;
    for(int i=height.size()-1;i>=0;i--){
	if(height[i]>tem_max) tem_max = height[i];
	right_max[i] = tem_max;
    }
    for(int i=0;i<height.size();i++){
        result+=((left_max[i]>right_max[i])?right_max[i]:left_max[i])-height[i];
    }
    return result;
}

int solve::twopass_solve(){
    /*可以看出来，mem_solve已经是O(n)的了，但是它从左到右，从右到左，进行了两次循环，实际上，我们发现，
     * 我们在每一个元素的left_max和right_max中只需要其中小的一个就行，我们可以从两边进行，这样只需要循环一次，而且只要
     * 这个过程中，在确定小的一遍进行求水容量即可，因为如果此时leftmax<rightmax,那么对应就是取leftmax作为容量上限*/
    int i=0;
    int j=height.size()-1;
    int leftmax=0;
    int rightmax=0;
    int result=0;
    while(i<j){
        if(leftmax<=rightmax){
	    if(leftmax<=height[i])leftmax = height[i];
	    else result += leftmax-height[i];
	    i++;
	}else {
	    if(rightmax<=height[j])rightmax = height[j];
	    else result += rightmax-height[j];
	    j--;
	}
    }
    return result;
}

int solve::stack_solve()
{
    /*这里用的是堆结构来解决这个问题。这个思路上上面的思路是不一样的。当遇见小的就入栈，遇见大的就出栈，直到小。这里的意思是，
     * 栈顶元素，前面和后面都是大于它值，这里计算容量的时候是要乘以序号之间相差的距离的，因为栈只能保证，前面的是小于它的但不是最小值*/
    stack<int> sta;
    int result=0;
    for(int i=0;i<height.size();i++){
        while(!sta.empty()&&height[sta.top()]<height[i]){
	    int tem = height[sta.top()];
	    sta.pop();
	    if(sta.empty())break;
	    result += ((height[i]>height[sta.top()]?height[sta.top()]:height[i])-tem)*(i-sta.top()-1);
	}
	sta.push(i);
    }
    return result;
}

int main()
{
    vector<int> a{0,1,0,2,1,0,1,3,2,1,2,1};
    solve s(a);
    cout<<s.stack_solve()<<endl;
    cout<<s.twopass_solve()<<endl;
    cout<<s.brute_force()<<endl;
    cout<<s.mem_solve()<<endl;
}
