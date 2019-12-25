#include <bits/stdc++.h>
using namespace std;

map<long long, long long> mp;

// https://www.hackerrank.com/challenges/stone-division-2/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign

long long dp_get(long long p){
    auto obj = mp.find(p);
    if(obj != mp.end()) return obj->second;
    return -1;
}

void dp_set(long long p, long long val){
    mp[p] = val;
}

long long max_moves(long long n, vector<int> &s){
    long long ans=0,a;
    long long dp = dp_get(n);
    if(dp != -1) return dp;
    for(auto m : s){
        if(n > m && n%m == 0){
            a = 1 + (n/m)*max_moves(m, s);
            ans = max(ans, a);
        }
    }
    dp_set(n, ans);
    return ans;
}

int main(){
    int q;
    cin >> q;
    while(q--){
        long long n,m;
        cin >> n >> m;
        vector<int> S(m);
        for(auto &num : S) cin >> num;
        cout << max_moves(n, S) << endl;
        mp.clear();
    }
}