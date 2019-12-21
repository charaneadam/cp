#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;


int n,m;
vector<int> a,b;
vector<vector<int>> dp;

int solve(int i, int j){
    if(i == n || j == m) return 0;
    int &ans = dp[i][j];
    if(ans != -1)
        return ans;
    int c1,x,y;
    int c2 = numeric_limits<int>::min();
    if(a[i] == b[j]){
        c1 = 1 + solve(i+1, j+1);
    }else{
        c1 = solve(i+1, j);
        c2 = solve(i, j+1);
    }
    return ans = max(c1, c2);
}

int main(){
//#ifndef ONLINE_JUDGE
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
//#endif
    int tc = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0) return 0;
        a.assign(n, 0);
        b.assign(m, 0);
        dp.assign(n+1, vector<int>(m+1, -1));
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> b[i];
        cout << "Twin Towers #" << tc++ << endl << "Number of Tiles : " << solve(0, 0) << endl << endl;
    }
    return 0;
}