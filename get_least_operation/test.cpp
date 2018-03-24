#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

int solve(string a,string b)
{
    vector<int> num1;
    vector<int> num2;
    for(int i=0;i<a.size();i++)
    {
        num1.push_back(a[i]-'0');
	num2.push_back(b[i]-'0');
    }
    vector<vector<int> > result{num1};
    vector<int> result_num{0};
    for(int i=0;i<a.size();i++)
    {
	vector<vector<int> > old;
	vector<int> old_num;
	for(int p=0;p<result.size();p++){
	       int swap_flag = 0;
	       for(int j=0;j<a.size();j++){
		    if(i==j)continue;
		    //cout<<"j"<<j<<endl;
		    //bool tem1 = !((result[p][j]-num2[j])>0)&&((result[p][i]-num2[j])>0);
		    //bool tem2 = !((result[p][j]-num2[i])<0)&&((result[p][i]-num2[i])<0);
		    //bool tem3 = result[p][j]==num2[i];
		    //bool tem4 = result[p][i]==num2[j];
		    bool tem5 = !(result[p][j]>=num2[j]||result[p][i]<=num2[i]);
		    if(num2[j]>num2[i]&&result[p][j]<result[p][i]&&tem5)
		    {
			vector<int> tem_change = result[p];
			int tem_num = result_num[p]+1;
			int tem = tem_change[j];
			tem_change[j]=tem_change[i];
			tem_change[i]=tem;
			old.push_back(tem_change);
			old_num.push_back(tem_num);
			//swap_flag = 1;
		    }
		}
	        //if(!swap_flag){old.push_back(result[p]);old_num.push_back(result_num[p]);}
		old.push_back(result[p]);old_num.push_back(result_num[p]);
        }
	result.swap(old);
	result_num.swap(old_num);
    }
    int min=INT_MAX;
    for(int i=0;i<result_num.size();i++){
	int tem = result_num[i];
	for(auto iter:result[i])cout<<iter<<" ";
	cout<<endl;
        for(int j=0;j<result[i].size();j++){
	    tem+=num2[j]-result[i][j]>0?(num2[j]-result[i][j]):(result[i][j]-num2[j]);
	}
	if(tem<min)min = tem;
    }
    return min;
}

int main(int argc,char** argv)
{
    string a = argv[1];
    string b = argv[2];
    //string a{"2123334"};
    //string b{"8987625"};
    cout<<solve(a,b)<<endl;
}
