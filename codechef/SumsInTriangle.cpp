#include <bits/stdc++.h>

using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

// https://www.codechef.com/submit-v2/SUMTRIAN?tab=statement

int main() {
    IOS;
    int t, n, total,m;
    cin >> t;
    while(t--){
        cin >> n;
        m = n;
        total = (n * (n+1))/2;
        vector<int> vec(total), best(total, -1);
        for(int i=0; i<total; i++){
            cin >> vec[i];
            if (total - i <= n) best[i] = vec[i];
        }
        while(--m){
            for(int j=(m * (m-1)/2), k=0; k<m; k++){
                int idx = j + k;
                int a = idx + m, b = a+1;
                best[idx] = vec[idx] + max(best[a], best[b]);
            }
        }
        cout << best[0] << endl;
    }
    return 0;
}
