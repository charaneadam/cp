#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        long long ans = a * (long long)(to_string(b+1).size() - 1);
        cout << ans << endl;
    }
}