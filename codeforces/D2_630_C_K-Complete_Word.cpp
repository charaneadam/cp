#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;

void read_input(){
    cin >> n >> k;
    cin >> s;
}

int solve(){
    vector<vector<int>> cnt(k, vector<int>(26, 0));
    for(int i=0; i<k; i++)
        for(int j=i; j<n; j+=k)
            cnt[i][s[j] - 'a']++;

    for(int i=0; i<k/2; i++){
        for(int j=0; j<26; j++){
            cnt[i][j] += cnt[k - i - 1][j];
        }
    }
    int ans = n;
    for(int i=0; i<(k+1)/2; i++){
        int mx = 0;
        for(int j=0; j<26; j++)
            mx = max(cnt[i][j], mx);
        ans -= mx;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        read_input();
        cout << solve() << endl;
    }
}