#include <bits/stdc++.h>
using namespace std;

int minCoinChange(vector<int> &coins, int V){
    int m = (int)coins.size();
    int *ans = new int[V+2];
    ans[0] = 0;
    for(int i=1; i<=V; i++) ans[i] = (int)1e9+5;
    for(int j=1; j<=V; j++){
        for(int i=0; i<m; i++){
            int coin = coins[i];
            if(coin <= j){
                ans[j] = min(ans[j], ans[j - coin] + 1);
            }
        }
    }
    return ans[V];
}

int main(){
    vector<int> coins = {1, 4, 7, 13, 28, 52, 91, 365};
    int v = 122;
    assert(minCoinChange(coins, v) == 5);
    return 0;
}