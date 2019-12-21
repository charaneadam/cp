#include <bits/stdc++.h>

using namespace std;

// To be continued ...

int n;
vector<int> p;

void read_input(){
    cin >> n;
    p.assign(n, 0);
    for(int i=0; i<n; i++) cin >> p[i];
}

void solve(){
    vector<int> brks;
    for(int i=1; i<n; i++){
        if(p[i] < p[i-1]){
            brks.push_back(i);
        }
    }
    if(brks.size() < 3){
        cout << "0 0 0" << endl;
        return;
    }
    int lst_brk=0;
    int lst_sz = brks[0];
    int sz = brks[0];
    for(int i=1; i<(int)brks.size(); i++){
        if(brks[i] - brks[lst_brk] > lst_sz){
            sz = brks[i];
            lst_sz = brks[i] - brks[lst_brk];
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        read_input();
        solve();
    }
    return 0;
}