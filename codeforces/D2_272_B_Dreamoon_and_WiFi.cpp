#include <bits/stdc++.h>

using namespace std;

vector<bool> vals;
int ans = 0;

void solve(string &s, int pos=0, int sum=0){
    if (pos == s.size()) {
        vals.push_back(sum == ans);
        return;
    }
    if(s[pos] == '+') solve(s, pos+1, sum+1);
    else if(s[pos] == '-') solve(s, pos+1, sum-1);
    else{
        solve(s, pos+1, sum+1);
        solve(s, pos+1, sum-1);
    }
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    for(auto c : s1)
        ans += (c == '+' ? 1 : -1);
    solve(s2);
    double res = 0;
    for(auto b : vals)
        if(b) res++;
    cout << setprecision(18) << res / vals.size();
}