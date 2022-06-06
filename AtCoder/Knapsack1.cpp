#include <vector>
#include <iostream>

using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define ll long long

// https://atcoder.jp/contests/dp/tasks/dp_d

class Knapsack {
private:
    int n, max_w;
    vector<int> w;
    vector<ll> v;
    vector<bool> chosen;
    vector<vector<ll>> ans;

    ll _solve(int rem, int last=0){
        if(rem == 0 || last == n) return 0;
        if(ans[last][rem] != -1) return ans[last][rem];
        ll a = 0, b;
        if(w[last] <= rem)
            a = v[last] + _solve(rem - w[last], last+1);
        b = _solve(rem, last+1);
        ans[last][rem] = max(a, b);
        return ans[last][rem];
    }
public:
    Knapsack(){
        cin >> n >> max_w;
        w.reserve(n);
        v.reserve(n);
        chosen.assign(n, false);
        ans.assign(n, vector<ll>(max_w+1, -1));
        for(int i=0; i<n; i++)
            cin >> w[i] >> v[i];
    }
    ll solve(){
        return _solve(max_w);
    }

};
int main() {
    IOS;
    Knapsack k;
    cout << k.solve();
    return 0;
}
