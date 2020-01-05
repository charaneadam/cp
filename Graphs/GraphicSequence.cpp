// https://d3gt.com/unit.html?graphic-sequence

#include <bits/stdc++.h>
using namespace std;

int n, *t;

bool isGraphicSequence(){
    int degrees_sum = 0;
    for(int i=0; i<n; i++) degrees_sum += t[i];
    bool ans = true;
    if(degrees_sum % 2) ans = false;
    for(int r=0; r<n-1; r++){
        int d = 0;
        int val = 0;
        for(int i=0; i<=r; i++){
            d += t[i];
        }
        for(int i=r+1; i<n; i++){
            val = min(r, t[i]);
        }
        ans &= (d <= r*(r-1) + val);
    }
    return ans;
}



int main(){
    cin >> n;
    t = new int[n];
    for(int i=0; i<n; i++) cin >> t[i];
    cout << isGraphicSequence();
}