#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long w = 0, o = 0, ww = 0, oo = 0;
    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == 'o'){
            o++;
            oo += w;
        }
        else
            if(i && s[i] == s[i-1]){
                w++;
                if(o){
                    ww += oo;
                }
            }
    }
    cout << ww;
}