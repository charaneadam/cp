#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,d;
        bool found = false;
        cin >> n >> d;
        long long mx = (int)sqrt(d) + 5;
        for(long long i = 0; i<mx && !found; i++){
            long long val = i + ((d+i)/(i+1));
            if(val <= n){
//                cout << i << ' ' << val << ' ' << d << ' ' << n << ' ';
                found = true;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
}