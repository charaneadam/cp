#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

// https://www.hackerrank.com/challenges/stone-division-2/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign

int dp_get(int p){
    auto obj = mp.find(p);
    if(obj != mp.end()) return obj->second;
    return -1;
}

void dp_set(int p, int val){
    mp[p] = val;
}

int max_moves(int n, vector<int> &s){
    if(n <= s[0])
        return 0;
    int a = dp_get(n);
    int ans = 0;
    if(a + 1) return a;
    bool divided = false;
    for(auto c : s){
        if(n>c && n%c == 0){
            a = 1 + (n/c) * max_moves(c, s);
            ans = max(a, ans);
            divided = true;
        }
    }
    if(!divided)
        return 0;
    dp_set(n, ans);
    return ans;
}

int main(){
    int q;
    cin >> q;
    while(q--){
        int n,m;
        cin >> n >> m;
        vector<int> S(m);
        for(auto &num : S) cin >> num;
        sort(S.begin(), S.end());
        cout << max_moves(n, S) << endl;
        mp.clear();
    }
}