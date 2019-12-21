#include <bits/stdc++.h>

#include <utility>

using namespace std;

class WordBreaker {
private:
    unordered_set<string> dict;
    string s;
    int n;
    vector<int> dp;

    bool isWord(int i, int j) {
        string word = s.substr(i, j);
        bool ans = dict.find(word) != dict.end();
        return ans;
    }

    bool solve(int pos = 0) {
        if (pos >= n)
            return true;
        int &ans = dp[pos];
        if(ans != -1) return ans;
        for (int j = 0; j+pos <= n; j++) {
            if (isWord(pos, j)) {
                if (solve(j+pos)) {
                    ans = 1;
                    return true;
                }
            }
        }
        ans = 0;
        return false;
    }

public:
    WordBreaker(string text, vector<string> &words) {
        this->s = move(text);
        this->n = (int) s.size();
        this->dp.assign(n+5, -1);
        for (auto &word : words) {
            this->dict.insert(word);
        }
    }

    bool TextIsSplittable() {
        return solve();
    }
};

int main() {
    vector<string> words = {"leet", "code"};
    string text = "leetcode";
    WordBreaker wb = *new WordBreaker(text, words);
    assert(wb.TextIsSplittable());
    text = "applepenapple";
    words = {"apple", "pen"};
    wb = *new WordBreaker(text, words);
    assert(wb.TextIsSplittable());
    text = "catsandog";
    words = {"cats", "dog", "sand", "and", "cat"};
    wb = *new WordBreaker(text, words);
    assert(!wb.TextIsSplittable());
//    cout << wb.isWord(0, 4);
}