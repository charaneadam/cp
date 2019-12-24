#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> vals(n), ans(n);
    for(auto &v : vals) cin >> v;
    sort(vals.begin(), vals.end());
    long long prefix = 0;
    for(int i=0; i<n; i++){
        prefix += vals[i];
        ans[i] = prefix;
        if(i >= m){
            ans[i] += ans[i - m];
        }
        cout << ans[i] << (i != n-1 ? ' ' : '\n');
    }
    return 0;
}