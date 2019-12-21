#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;

vector<int> scores;
vector<int> path;
vector<int> dp;
int n;

int solve(int rem){
    if(rem < 0) return -1;
    if(rem == 0) return 0;
    int &ans = dp[rem];
    if(ans != -1) return ans;
    int a;
    for(int i=0; i<n; i++){
        a = 1 + solve(rem - scores[i]);
        if(a){
            if(ans == -1) ans = a;
            if(a <= ans)
                path[rem] = i;
            ans = min(a, ans);
        }
    }
    return ans;
}

int main(){
    int tc;
    cin >> tc;
    for(int t = 1; t<=tc; t++){
        int s;
        cin >> n >> s;
        scores.assign(n, 0);
        path.assign(s+5, -1);
        dp.assign(s+1, -1);
        path[0] = 0;
        for(int &score : scores)
            cin >> score;
        int ans = solve(s);
        cout << "Case " << t << ": ";
        if(ans == -1)
            cout << "impossible";
        else{
            cout << '[' << ans << "] ";
            while(s){
                cout << scores[path[s]] << ' ';
                s -= scores[path[s]];
            }
        }
        cout << endl;
    }
    return 0;
}