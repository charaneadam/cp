#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int j, string &X, string &Y){
    if(i == X.size()) return true;
    if(j == Y.size()) return false;
    if(X[i] == Y[j]) return solve(i+1, j+1, X, Y);
    return solve(i, j+1, X, Y);
}

int main(){
    string X = "PPAP";
    string Y = "PENPINEAPPLEAPPLEPEN";
    cout << solve(0, 0, X, Y);
}