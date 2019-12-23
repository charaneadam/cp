#include <bits/stdc++.h>
using namespace std;

bool isWord(int i, int j, string &s, unordered_set<string> &dict){
    int len = j-i+1;
    return dict.find(s.substr(i, len)) != dict.end();
}

int numberofPartitions(string &s, vector<string> &words){
    unordered_set<string> dict;
    for(auto word : words) dict.insert(word);
    int n = (int)s.size();
    vector<int> ans(n+1, 0);
    ans[n] = 1;
    for(int i=n-1; i>=0; i--){
        ans[i] = 0;
        for(int j=i; j<n; j++){
            bool isword = isWord(i, j, s, dict);
            string word = s.substr(i, j-i+1);
            if(isword){
                ans[i] += ans[j+1];
            }
        }
    }
    return ans[0];
}

int main(){
    vector<string> dict = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
    string s = "ilikesamsungicecreammangomango";
    assert(numberofPartitions(s, dict) == 16);
    s = "mangomango";
    assert(numberofPartitions(s, dict) == 4);
    s = "ARTISTOIL";
    dict = {"ARTIST", "OIL", "IS", "ART", "TOIL"};
    assert(numberofPartitions(s, dict) == 2);
    return 0;
}
