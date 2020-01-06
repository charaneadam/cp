#include <bits/stdc++.h>
using namespace std;

int helper(bool o, int &n1, int &n2, int p, bool lst){
    int ans = 0;
    int n_1 = n1, n_2 = n2;
    if(!o) swap(n_1, n_2);
    if(p > n_1){
        p -= n_1;
        n_1 = 0;
        ans++;
        n_2 -= p;
        if(lst == o) ans++;
    }
    else{
        n_1 -= p;
        if(lst != o) ans++;
    }
    if(!o) swap(n_1, n_2);
    n1 = n_1;
    n2 = n_2;
    return ans;
}

int solve(vector<pair<bool, int>> &pos, int e, int o){
    int even = e;
    int odd = o;
    int m = (int)pos.size();
    int ans = 0;
    for(int i=0; i<m; i++){
        bool is_odd = pos[i].first;
        int idx = pos[i].second;
        if(i == 0){
            int available_places_before = idx - 1;
            ans += helper(is_odd, odd, even, available_places_before, is_odd);
        }
        else if(i == m-1){
            int available_places_before = 0;
            bool lst = is_odd;
            if(m - 1){
                available_places_before = idx - pos[i-1].second - 1;
                lst = pos[i-1].first;
            }
            ans += helper(is_odd, odd, even, available_places_before, lst);

            ans += (is_odd ? (even ? 1 : 0) : (odd ? 1 : 0));
        }
        else{
            int available_places_before = idx - pos[i-1].second - 1;
            bool lst = pos[i-1].first;
            ans += helper(is_odd, odd, even, available_places_before, lst);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int even = n/2, odd = (n+1)/2;
    vector<pair<bool,int>> pos, rev_pos;
    int a,e=-1,o;
    for(int _=1; _<=n; _++){
        cin >> a;
        if(a){
            if(a%2) odd--;
            else even--;
            pos.emplace_back(a%2, _);
            e++;
        }
    }

    for(; e>=0; e--)
        rev_pos.emplace_back(pos[e].first, n + 1 - pos[e].second);

    e=even, o=odd;

    int ans1 = solve(pos, even, odd);
    int ans2 = solve(rev_pos, e, o);
//    cout << ans1 << ' ' << ans2;
    cout << min(ans1, ans2);
    return 0;
}