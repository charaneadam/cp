#include <bits/stdc++.h>
using namespace std;

int n;
string A,B;

vector<int> dp;

int solve(int i=0, int sum=0){
    if(i == n) return sum;
    if(i == n-1){
        int ret = (int)(A[i] != B[i]);
        return ret + sum;
    }
    int &ans = dp[i];
    if(ans != -1) return ans;
    if(A[i] == B[i]){
        return ans = solve(i+1, sum);
    }
    else{
        if(A[i+1] != B[i+1] && A[i] != A[i+1]){
            return ans = solve(i+2, sum+1);
        }
        else{
            return ans = solve(i+1, sum+1);
        }
    }
}

int solve2(){
    int ans = 0;
    int i=0;
    while(i<n){
        if(A[i] != B[i]){
            ans++;
            if(i+1<n && A[i+1] != B[i+1] && A[i] != A[i+1]){
                i++;
            }
        }
        i++;
    }
    return ans;
}

int main(){
    cin >> n;
    cin >> A >> B;
    dp.assign(n+1, -1);
    cout << solve2();
}