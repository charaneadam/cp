#include <bits/stdc++.h>
using namespace std;

int m,n;
string A,B;

int lcs(int i, int j){
    if(i == m || j == n) return 0;
    if(A[i] == B[j]) return 1 + lcs(i+1, j+1);
    return max(lcs(i+1, j), lcs(i, j+1));
}

int LengthOfShortestCommonSuperSequence(){
    return n+m - lcs(0,0);
}

int main(){
    A = "AGGTAB";
    m = (int)A.size();
    B = "GXTXAYB";
    n = (int)B.size();
    cout << lcs(0, 0);
    cout << endl << LengthOfShortestCommonSuperSequence();
}