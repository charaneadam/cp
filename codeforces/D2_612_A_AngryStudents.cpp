#include <bits/stdc++.h>
using namespace std;

// http://codeforces.com/contest/1287/problem/A

int main(){
    int groups;
    cin >> groups;
    for(int _=0; _<groups; _++){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 0, curr_ans=0;
        bool a = false;
        for(auto c : s){
            if(c == 'P'){
                if(a) curr_ans++;
            }
            else{
                a = true;
                ans = max(ans, curr_ans);
                curr_ans = 0;
            }
        }
        ans = max(ans, curr_ans);
        cout << ans << endl;
    }
    return 0;
}