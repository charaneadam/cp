#include <bits/stdc++.h>
using namespace std;


// Something's wrong with memory usage ! lot osf stuffs to check.

string s1,s2;
int n1,n2;
map<pair<pair<int, int>,pair<int, int>>, bool> mp;

string get(int n, int s, int e){
    if(n)
        return s2.substr(s, e-s+1);
    else
        return s1.substr(s, e-s+1);
}

bool put(pair<pair<int, int>,pair<int, int>> state, bool ans){
    mp[state] = ans;
    return ans;
}

bool calculated(bool &found, int b1, int e1, int b2, int e2){
    pair<pair<int, int>,pair<int, int>> state;
    state = {{b1, e1}, {b2, e2}};
    auto it = mp.find(state);
    found = (it != mp.end());
    return (found ? it->second : false);
}

bool solve(int b1, int e1, int b2, int e2){
    pair<pair<int, int>,pair<int, int>> state;
    state = {{b1, e1}, {b2, e2}};
    if(e1-b1 != e2 - b2){
        bool ans = false;
        return put(state, ans);
    }
    if(e1 == b1 || e2 == b2){
        bool ans = get(0, b1, e1) == get(1, b2, e2);
        return put(state, ans);
    }
    bool state_already_calculated;
    bool ans = calculated(state_already_calculated, b1, e1, b2, e2);
    if(state_already_calculated)
        return ans;
    string subs0 = get(0, b1, e1);
    string subs1 = get(1, b2, e2);
    if(subs0 == subs1){
        ans = true;
        return put(state, ans);
    }
    int mid0 = (e1 )/2;
    int mid1 = (e2 )/2;
    bool a = solve(b1, mid0, b2, mid1);
    bool b = solve(b1, mid0, mid1+1, e2);
    bool c = solve(mid0+1, e1, b2, mid1);
    bool d = solve(mid0+1, e1, mid1+1, e2);
    ans = ((a && d ) || (b && c));
    return put(state, ans);
}

int main(){
    cin >> s1 >> s2;
    n1 = (int)s1.size();
    n2 = (int)s2.size();
    if(n1 != n2)
        cout <<  "NO";
    else
        cout << (solve(0, n1-1, 0, n1-1) ? "YES" : "NO");
    return 0;
}