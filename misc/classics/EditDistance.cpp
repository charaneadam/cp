#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <limits>

using namespace std;

const int maximum = 1000;

string s1, s2;
int n1, n2;
vector<vector<int>> dp;

int min(int x, int y, int z){
    return min(min(x, y), z);
}

int editDist(int m, int n){
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    if (dp[m - 1][n - 1] != -1)
        return dp[m - 1][n - 1];

    if (s1[m - 1] == s2[n - 1])
        return dp[m - 1][n - 1] = editDist(m - 1, n - 1);

    return dp[m - 1][n - 1] = 1 + min(editDist(m, n - 1),editDist(m - 1, n),editDist(m - 1, n - 1));
}


int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n1 >> n2;
        cin >> s1 >> s2;
        dp.assign(n1, vector<int>(max(n1, n2), -1));
        cout << editDist(n1, n2) << endl;
    }
    return 0;
}