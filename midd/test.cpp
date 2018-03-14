#include <vector>
#include <iostream>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> li;
        vector<int> mu;
        if(n1<=n2){
            li = nums1;
            mu = nums2;
        }else{
            li = nums2;
            mu = nums1;
        }

        n1 = li.size();
	cout<<n1<<endl;
        n2 = mu.size();
	cout<<n2<<endl;
        int mini = 0; int maxi =n1;
        int hal = (n1+n2+1)/2;//mid at left for odd
        while(mini<=maxi){
            //search for perfect i
            int i = (mini+maxi)/2;
            int j = hal-i;
            if(i>mini&&li[i-1]>mu[j]){
                mini = i+1;
            }else if(i<maxi&&mu[j-1]>li[i]){
                maxi = i-1;
            }else{
                int leftMax = 0;
                if(i==0)leftMax = mu[j-1];
                else if(j==0)leftMax = li[i-1];
                else leftMax = mu[j-1]>li[i-1]?mu[j-1]:li[i-1];
                if((n1+n2)%2==1)return leftMax;
                int rightMin = 0;
                if(i==n1)rightMin = mu[j];
                else if(j==n2) rightMin = li[i];
                else rightMin = mu[j]>li[i]?li[i]:mu[j];
                return (leftMax+rightMin)/2.0;
                
            }
        }
        return 0.0;
}

int main()
{
 vector<int> a{1,3};
 vector<int> b{2};
 cout<<findMedianSortedArrays(a,b);
}
