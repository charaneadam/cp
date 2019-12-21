#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <limits>

using namespace std;

int m;
vector<int> t;
vector<vector<int>> dp;

int LCS(int i, int prev){
    if(i1 == m)
        return 0;
    int &ans = dp[i1][i2];
    if(ans != -1) return ans;

    int choice1 = LCS(i1 + 1, i2);
    int choice2 = 0;

    if(i2 == m || t[i2] < t[i1])
        choice2 = LCS(i1 + 1, i1) + 1;

    return ans = max(choice1, choice2);
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> m;
        t.assign(m, 0);
        dp.assign(m+2, vector<int>(m+2, -1));
        for(int i=0; i<m; i++) cin >> t[i];
        cout << LCS(0, m) << endl;
    }
    return 0;
}