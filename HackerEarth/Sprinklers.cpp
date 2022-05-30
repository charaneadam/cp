#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/sprinklers-7153515e/

using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


int main() {
    IOS;

    int t,n,q,rng,l,r,mn,mx,req;
    cin >> t;
    while(t--){
        mn = 1000000;
        mx = -1000000;
        unordered_map<int, int> freq;
        cin >> n >> q;
        vector<int> sp(n);
        vector<pair<int, int>> intervals(n);
        for(int i=0; i<n; i++) cin >> sp[i];
        for(int i=0; i<n; i++){
            cin >> rng;
            if(sp[i] > 0){
                l = max(1, sp[i] - rng);
                r = sp[i] + rng;
            }
            else{
                l = sp[i] - rng;
                r = min(-1, sp[i] + rng);
            }
            if(l < mn) mn = l;
            if(r > mx) mx = r;
            intervals[i] = {l, r};
            freq[l] = freq[l] + 1;
            freq[r+1] = freq[r+1] - 1;
        }
        for(int i=mn; i<mx+1; i++){
            freq[i] = freq[i] + freq[i-1];
        }
        while(q--){
            cin >> req;
            cout << max(0, freq[req]) << endl;
        }
    }

    return 0;
}
