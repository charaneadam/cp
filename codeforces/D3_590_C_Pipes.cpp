#include <bits/stdc++.h>
using namespace std;

int n;
string t[2];
vector<vector<short int>> memo;

bool solve(int i=0, int j=0, int k=0){
    // top down solution
    if(j == n) return (bool)(i);
    short &dp = memo[i][j];
    if(dp != -1)
        return (bool)dp;
    int s = (t[i][j] - '0');
    if(i == k){
        if(s >= 3){
            return dp = solve(1-i, j, i);
        }
        else{
            return dp = solve(i, j+1, i);
        }
    }
    else{
        if(s >= 3){
            return dp = solve(i, j+1, i);
        }
        else{
            return dp = false;
        }
    }
}

bool solve2(){
    // bottom up solution
    int cur = 0;
    bool good = true;
    for(int j=0; j<n && good; j++){
        if(t[cur][j] > '2'){
            cur = 1-cur;
            if(t[cur][j] <= '2'){
                good = false;
            }
        }
    }
    return (good ? cur : false);
}

int main(){
    int q;
    cin >> q;
    while(q--){
        cin >> n;
        memo.assign(2, vector<short int>(n, -1));
        cin >> t[0] >> t[1];
        if(solve2()) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}