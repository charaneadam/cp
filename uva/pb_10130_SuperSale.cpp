#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <limits>

using namespace std;

vector<vector<int>> dp;
vector<int> prices, weights, mws;
int n,g;

int solve(int pos, int rem){
    if(pos == n || rem < 0)
        return 0;
    int &ans = dp[pos][rem];
    if(ans != -1) return ans;
    int a = solve(pos+1, rem);
    int b = 0;
    if(rem >= weights[pos])
        b = prices[pos] + solve(pos+1, rem-weights[pos]);
    return ans = max(a, b);
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n;
        prices.assign(n, 0);
        weights.assign(n, 0);
        dp.assign(n+2, vector<int>(32, -1));
        for(int i=0; i<n; i++){
            cin >> prices[i] >> weights[i];
        }
        cin >> g;
        mws.assign(g, 0);
        int ans = 0;
        for(int i=0; i<g; i++){
            cin >> mws[i];
            ans += solve(0, mws[i]);
        }
        cout << ans << endl;
    }
    return 0;
}