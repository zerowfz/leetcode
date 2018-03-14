#include <iostream>
#include <vector>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {
        int i =0;
        int j=nums.size()-1;
        int mid;
        int re=-1;
        while(i<=j){
            int tem1 = nums[i];
            int tem2 = nums[j];
            if(target==tem1){re=i;break;}
            if(target==tem2){re=j;break;}
            mid = (i+j)/2;
	    cout<<i<<" "<<j<<endl;
	    cout<<mid<<endl;
            int tem3 = nums[mid];
	    cout<<tem3<<endl;
            if(target==tem3){re=mid;break;}
            if(target <tem3) {i++;j=mid-1;}
            else{j--;i=mid+1;}
	    cout<<i<<" "<<j<<endl;
	    cout<<"sadfsf"<<endl;
        }
        if(re==-1)return vector<int>{-1,-1};
        int left = re;
        int right = re;
        while(left>=0&&nums[left]==target){left--;};
        while(right<nums.size()&&nums[right]==target)right++;
        return vector<int>{left+1,right-1};
    }

int main()
{
    vector<int> nums{0,0,1,1,2,2,2,2,3,3,4,4,4,5,6,6,6,7,8,8};
    vector<int> result = searchRange(nums,4);
    for (auto a:result)cout<<a<<endl;
}
