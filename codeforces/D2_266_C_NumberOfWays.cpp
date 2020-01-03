#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    auto *t = new long long[n];
    long long sum = 0;
    for(int i=0; i<n; i++){
        cin >> t[i];
        sum += t[i];
    }
    if(sum % 3){
        cout << 0;
        return 0;
    }
    long long p1 = sum / 3;
    long long p2 = p1 * 2;
    sum = 0;
    long long ans = 0;
    int cnt = 0;
    for(int i=0; i<n-1; i++){
        sum += t[i];
        if(sum == p2) ans += cnt;
        if(sum == p1) cnt++;
    }
    cout << ans;
    return 0;
}