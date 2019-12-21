#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <limits>

using namespace std;

int n1, n2;
string s1, s2;

vector<vector<int>> dp;

int LCS(int i1, int i2){
    if(i1 == n1 || i2 == n2) return 0;
    int &ans = dp[i1][i2];
    if(ans != -1) return ans;
    int a = LCS(i1 + 1, i2);
    int b = 0;
    if(s1[i1] == s2[i2])
        b = 1 + LCS(i1 + 1, i2 + 1);
    else
        b = LCS(i1, i2 + 1);
    return ans = max(a, b);
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n1 >> n2;
        dp.assign(n1, vector<int>(n2, -1));
        cin >> s1 >> s2;
        cout << LCS(0, 0) << endl;
    }
    return 0;
}