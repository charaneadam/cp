#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k,ans,tmp;
    cin >> n >> k;
    string s;
    cin >> s;
    s += '#';
    set<char> st;
    for(int i=0; i<k; i++){
        char c;
        cin >> c;
        st.insert(c);
    }
    ans = tmp = 0;
    for(auto c : s){
        if(st.find(c) == st.end()){
            ans += (tmp * (tmp + 1)) / 2;
            tmp = 0;
        }
        else tmp++;
    }
    cout << ans;
}