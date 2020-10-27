#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<int> c(n);
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> a[i][j];
                if(!j){
                    mp[a[i][j]] = i;
                }
            }
        }

        int tmp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> tmp;
                if(mp.find(tmp) != mp.end()) c[j] = tmp;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << a[mp[c[i]]][j] << ' ';
            }
            cout << endl;
        }

    }
}