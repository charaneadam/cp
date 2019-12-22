#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int T, vector<int> &X){
    int n = (int)X.size();
    vector<vector<int>> D(n+2, vector<int>(T+1));
    D[n+1][0] = true;
    for(int t=1; t<=T; t++){
        D[n+1][t] = false;
    }

    for(int i=n; i>=1; i--){
        D[i][0] = true;
        for(int t=1; t<=X[i]-1; t++){
            D[i][t] = D[i+1][t];
        }
        for(int t=X[i]; t<=T; t++){
            D[i][t] = D[i+1][t] || D[i+1][t-X[i]];
        }
    }
    return D[1][T];
}

int main(){
    vector<int> nums = {15, 22, 14, 26, 32, 9, 16, 8};
    int t = 53;
    cout << subsetSum(t, nums);
}