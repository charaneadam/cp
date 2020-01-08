#include <bits/stdc++.h>
using namespace std;

const unordered_set<int> bad = {1, 2, 3, 5, 7, 11};

bool isBad(int n){
    auto it = bad.find(n);
    return it != bad.end();
}

int main(){
    int q;
    cin >> q;
    while(q--){
        int a, ans=0;
        cin >> a;
        if(a < 13 && isBad(a)) cout << -1;
        else{
            if(a%2) a -= 9, ans++;
            if(a % 4) a -= 6, ans++;
            ans += a/4;
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}