#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;


int solve(int pos, vector<int> &s, vector<int> &arr){
    if(pos == n) return 0;
    int a=0,b;
    int &ans = dp[pos];
    if(ans != -1) return ans;
    b = solve(pos + 1, s, arr);
    if(arr.empty() || (arr.back() < s[pos] && __gcd(arr.back(), s[pos]) > 1)){
        arr.push_back(s[pos]);
        a = 1 + solve(pos + 1, s, arr);
        arr.pop_back();
    }
    return ans = max(a, b);
}

int main(){
    cin >> n;
    vector<int> s(n), arr;
    dp.assign(n, -1);
    sort(s.begin(), s.end());
    for(auto &c : s) cin >> c;
    cout << solve(0, s, arr);
    return 0;
}