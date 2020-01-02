#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m;
    vector<vector<int>> d(n+1, vector<int>(m+1));
    vector<vector<int>> t(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> d[i][j];
            t[i][j] = d[i][j] + t[i-1][j] + t[i][j-1] - t[i-1][j-1];
        }
    }
    cin >> q;
    while(q--){
        cin >> n >> m;
        cout << t[n][m] << endl;
    }
}