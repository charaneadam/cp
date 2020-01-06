#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(n+1, {10000000, 10000000}));
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    dp[0][0] = {0, 0};
    for(int i=1; i<=n; i++)
        for(int j=0; j<=i; j++){
            if(a[i]%2 == 0) dp[i][j].first = min(dp[i-1][j-1].first, dp[i-1][j-1].second+1);
            if(a[i]%2==1 || a[i]==0) dp[i][j].second = min(dp[i-1][j].first+1, dp[i-1][j].second);
        }
    cout<<min(dp[n][n/2].first,dp[n][n/2].second);
}