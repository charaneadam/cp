#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int solve(int r, int g){
    int h = 1000;
    while(h*(h+1)/2 > r+g) h--;
    if(r > g) swap(r, g);
    vector<int> dp(r, 0);
    dp[0] = 1;
    int ans = 0;
    for(int i = 1 ; i <= h ; i++)
        for(int j = r ; j >= i ; j--) {
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    h = h * (h + 1) / 2;
    for(int i = 0 ; i <= r ; i++)
        if(h - i <= g) {
            ans += dp[i];
            ans %= MOD;
        }
    return ans;
}


int main(){
    int a,b;
    cin >> a >> b;
    cout << solve(a, b);
}