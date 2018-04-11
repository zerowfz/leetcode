/*
 *华为笔试题，输入以字符串"2,3,4,-5,-3,8"，输出最大连续子序列的和
 *这个问题第一个难点：在于将字符串变成数字，按照这个格式（这里当遇见','的时候，即说明一个数字已经生成了）
 第二个问题就是在于解决最大和的问题，最大和，在对字符串进行遍历的过程中，用sum来统计子序列的和，最大值，只存在于
 当加上这个数，之后，sum是大于0的，就继续加数上去，而当sum<=0的时候，就以下一个数字作为子序列的开始。
 *
 * */
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
	while(1){
  string vec;
  cin>>vec;
  vec = vec+",";
  int neg=1;
  int tem;
  int end=1;
  int sum;
  int max=INT_MIN;
  int max_neg=INT_MIN;
  int restart=1;
  for(int i=0;i<vec.size();i++){
      if(vec[i]==','){
          tem = neg*tem;
          cout<<tem<<" ";
	  if(restart){sum = tem;restart=0;}
	  else{
	  if(tem<0){
	      if(tem+sum>0)sum+=tem;
	      else restart=1;
	  }else {if(sum<0)sum=0;sum += tem;}
	  }
	  if(sum>max)max=sum;
	  end=1;neg=1;
	  continue;
      }
      if(vec[i]=='-'){neg=-1;continue;}
      if(end==1){tem=vec[i]-'0';
	      //cout<<tem<<endl;
	      end=0;continue;}
      if(!end) {tem = tem*10+(vec[i]-'0');
	      //cout<<tem<<endl;
	      }
  }
  cout<<endl;  
  cout<<max<<endl;
  }
}
