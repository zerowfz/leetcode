#include <string>
#include <iostream>
#include <vector>
using namespace std;
vector<string> letterCombinations(string digits) {
        vector<string> map{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result ;
        for(auto iter1=digits.begin();iter1!=digits.end();iter1++){
            int num = *iter1-'0';
	    cout<<num<<endl;
            if(num<0||num>9)break;
            string lett = map[num];
            if (lett.empty())continue;
            vector<string> temp;
            for (auto iter3=lett.begin();iter3!=lett.end();iter3++){
                if(result.empty())temp.push_back();
                else
                for(auto iter2=result.begin();iter2!=result.end();iter2++){
                    temp.push_back((*iter2)+(*iter3));
            }
            }
            result.swap(temp);
    }
        return result;
    } 
int main()
{
 letterCombinations("");
}
