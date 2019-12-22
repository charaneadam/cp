#include <bits/stdc++.h>
using namespace std;

int editDistance(string &s1, string &s2){
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dist(m+1, vector<int>(n+1));
    for(int j=0; j<=n; j++){
        dist[0][j] = j;
    }
    for(int i=1; i<=m; i++){
        dist[i][0] = i;
        for(int j=1; j<=n; j++){
            int ins = dist[i-1][j] + 1;
            int del = dist[i][j-1] + 1;
            int rep = dist[i-1][j-1];
            if(s1[i] != s2[j]) rep++;
            dist[i][j] = min(min(ins, del), rep);
        }
    }
    return dist[m][n];
}

int main(){
    string s1 = "AAAB";
    string s2 = "AAB";
    assert(editDistance(s1, s2) == 1);
    s1 = "ALGORITHM";
    s2 = "ALTRUISTIC";
    assert(editDistance(s1, s2) == 6);
}