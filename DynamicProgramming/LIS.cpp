#include <bits/stdc++.h>
using namespace std;

int LISBottomUp(vector<int> &t){
    int n = (int)t.size();
    vector<int> a(n+1);
    a[0] = numeric_limits<int>::min();
    for(int i=0; i<n; i++){
        a[i+1] = t[i];
    }
    vector<vector<int>> LISBigger(n+1, vector<int>(n+1, 0));
    for(int j=n; j>=1; j--){
        for(int i=0; i<j; i++){
            int keep = 1 + LISBigger[j][j+1];
            int skip = LISBigger[i][j+1];
            if(a[i] >= a[j]){
                LISBigger[i][j] = skip;
            }
            else{
                LISBigger[i][j] = max(skip, keep);
            }
        }
    }
    return LISBigger[0][1];
}

int LISBottomUp2(vector<int> &t){
    int n = (int)t.size();
    vector<int> a(n+1);
    vector<int> Lisfirst(n+1);
    a[0] = numeric_limits<int>::min();
    for(int i=0; i<n; i++){
        a[i+1] = t[i];
    }
    for(int i=n; i>=0; i--){
        Lisfirst[i] = 1;
        for(int j=i+1; j<=n; j++){
            if(a[j] > a[i] && 1 + Lisfirst[j] > Lisfirst[i]){
                Lisfirst[i] = Lisfirst[j] + 1;
            }
        }
    }
    return Lisfirst[0] -1;
}

int main(){
    vector<int> t = {1, 5, 2, 3, 4, 8};
    assert(LISBottomUp(t) == 5);
    assert(LISBottomUp(t) == LISBottomUp2(t));
}