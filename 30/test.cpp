#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
        int len_word = words[0].size();
        unordered_map<string,int> count;
        vector<int> result;
        for(auto iter = words.begin();iter!=words.end();iter++)
        {
            count[*iter]++;
        }
	for(auto i:count)cout<<i.first<<i.second<<endl;
        for(int iter=0;iter<(s.size()-len_word+1);iter++)
        {
            string tem = s.substr(iter,len_word);
            int iter2 = iter;
            int c=0;
            auto tem3 = count;
	    cout<<tem3[tem]<<endl;
            while(tem3[tem]){
		tem3[tem]--;
                iter2+=len_word;
                tem = s.substr(iter2,len_word);
		cout<<tem<<endl;
                c++;
                }
            if(c==words.size())result.push_back(iter);
        }
        return result;       
}

int main()
{
	string s = "barfoothefoobarman";
	vector<string> words{"foo","bar"};
        vector<int> a = findSubstring(s,words);
	for(auto c:a)cout<<c<<endl;
}
