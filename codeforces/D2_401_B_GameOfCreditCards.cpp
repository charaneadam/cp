#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s1,s2;
    cin >> n >> s1 >> s2;
    vector<int> p1(n),p2(n);
    for(int i=0; i<n; i++){
        p1[i] = s1[i] - '0';
        p2[i] = s2[i] - '0';
    }


    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    int idx1, idx2, mx, mn;
    idx1 = idx2 = 0;
    mx = 0;
    for(; idx2<n; idx2++){
        if(p2[idx2] > p1[idx1]){
            idx1++;
            mx++;
        }
    }


    idx1 = idx2 = 0;
    mn = n;
    sort(p1.begin(), p1.end(), greater<>());
    sort(p2.begin(), p2.end(), greater<>());
    for(; idx1<n; idx1++){
        if(p2[idx2] >= p1[idx1]){
            idx2++;
            mn--;
        }
    }

    cout << mn << endl << mx;
    return 0;
}