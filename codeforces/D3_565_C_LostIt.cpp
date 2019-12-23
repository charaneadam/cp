#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a;
    cin >> n;
    int t[] = {4,8,15,16,23,42};
    unordered_map<int, int> mp;
    for(int i=0; i<6; i++){
        mp[t[i]] = i;
    }
    int cnt[6] = {0};
    for(int i=0; i<n; i++){
        cin >> a;
        a = mp[a];
        if(a){
            if(cnt[a-1] > cnt[a]){
                cnt[a]++;
            }
        }
        else{
            cnt[a]++;
        }
    }
    int mn = cnt[0];
    for(int i=1; i<6; i++) mn = min(mn, cnt[i]);
    cout << n - mn*6;
}