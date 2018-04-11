/*
 *jump game：这个问题的意思是给定一个数组，数组每一个位置的值，表示可以跳的最大长度，
 每一个位置的序号，表示的是其所在位置，问，从0开始，是否跳到最后位置。
 例如array = [2,3,1,1,4] 则返回true (因为0->1->4)
 例如[3,2,1,0,4] 则返回false 因为没有可能从0到最后一个位置
 针对这个问题，有很多种解法
 1.暴力，即从0开始，搜索可能到的位置，然后再迭代去找后面可能的当找到一个解，即可以。
 2.显然对于上面的子问题中是由重复的，假设问题P(i)表示以i为起始位置，能否到达终点的子问题，按照1中的解法
 其中当然是有很多重复的，所以考虑用动态规划问题，top-down的写法，再每一次遇到一个子问题的时候，将该问题记录下来。
 这个时候算法复杂度对应的是O(N^2)因为对于一个子问题，我们需要对其所有的array[i]进行遍历,array[i]<N（这里实际上是说同一个子问题中有很多中可能，也就是
 有更多的子问题发生）,所以对应O(N),一共N个子问题
 所以对应O(N^2)。
 3.bottom-up，我们可以考虑从右往左进行遍历，这样的话，就类似于bottom-up的方法，我们先计算出来了右边有哪些有可能存在true。
 这里一开始自己想的话，不能理解到bottom-up的想法，因为一直局限在，以前动态规划中的，bottomup就一定是固定的子问题，然后一层一层的向上求解
 实际上，这里很容易想，我们的top-down的方法，是从左到右，不知道哪一个位置可能到达，就向下迭代，那么对应bottm-up的方法就是从右到左，找到可以
 到达的点，然后再看前面的点能否到达这个点。
 4.greedy 贪婪算法，标答上说，是从bottom-up方法中很自然想到的，可以这样理解。我们如果从右往左的过程中，找到了一个位置j可以到达最后一个位置，那么很显然，
 如果前面有个位置能到达最后一个位置，那么它肯定也可以到达J这个位置，说明，此时实际上我们有将j作为最后的位置。也就是说这样的话，我的每一次的子问题都是
 最贪婪的，只有一个子问题，就是对应可以到达最后一个位置的点。这样的话对应的就是O(N)
 * */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
  public:
    Solution(vector<int> nums):nums(nums){
	    for(auto i:nums)
		    mem.push_back(-1);
	    mem[nums.size()-1]=1;
    }
    bool solve_ori(int);
    bool solve_top(int);
    bool solve_bottom();
    bool solve_greedy();
    vector<int> mem;
    vector<int> nums;
    void reset(){
        for(int i=0;i<mem.size();i++)mem[i]=-1;
	mem[nums.size()-1]=1;
	
    }

};

bool Solution::solve_ori(int i){
    int furest_path = (nums[i]+i>nums.size()-1)?nums.size()-1:nums[i]+i;
    if(furest_path==nums.size()-1)return true;
    for(int j=i+1;j<=furest_path;j++){
        if(solve_ori(j))return true;
    }
    return false;
}

bool Solution::solve_top(int i){
    int furest_path = (nums[i]+i>nums.size()-1)?nums.size()-1:nums[i]+i;
    if (mem[i]==-1){
    if(furest_path == nums.size()-1){
	    mem[i] = 1;
            //cout<<"a"<<mem[i]<<" ";
	    return true;
    }
    for(int j=i+1;j<=furest_path;j++)
	    if(solve_top(j)){
	        mem[i]=1;
	    //	cout<<"b"<<mem[i]<<" ";
		return true;
	    }
    //cout<<"c"<<mem[i]<<" ";
    mem[i]=0;
    return false;
    }
    //cout<<"d"<<mem[i]<<" ";
    return mem[i];
}

bool Solution::solve_bottom(){
   for(int j=nums.size()-2;j>=0;j--){
       //cout<<mem[j]<<"###";
       int furest_path = (nums[j]+j>nums.size()-1)?nums.size()-1:nums[j]+j;
       //cout<<furest_path<<"**";
       for(int i = j+1;i<=furest_path;i++){
           if(mem[i]==1){
	       mem[j]=1;
	       break;
	   }
       }
       if(mem[j]==-1)mem[j]=0;
       //cout<<mem[j]<<"****";
   } 
   return mem[0];
}

bool Solution::solve_greedy(){
    int k = nums.size()-1;
    for(int j=nums.size()-2;j>=0;j--){
	if(j+nums[j]>=k)k=j;
    }
    return k==0;
}

int main(){
    Solution solve(vector<int> {3,2,1,0,4});
    //for(auto i:solve.mem)cout<<i<<" ";
    //cout<<endl;
    cout<<solve.solve_greedy()<<endl;
    solve.reset();
    //for(auto i:solve.mem)cout<<i<<" ";
    //cout<<endl;
    cout<<solve.solve_bottom()<<endl;
    //for(auto i:solve.mem)cout<<i<<" ";
    //cout<<endl;
    solve.reset();
    //for(auto i:solve.mem)cout<<i<<" ";
    //cout<<endl;
    cout<<solve.solve_top(0)<<endl;
    //for(auto i:solve.mem)cout<<i<<" ";
    //cout<<endl;
    solve.reset();
    cout<<solve.solve_ori(0)<<endl;

}
