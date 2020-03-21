#include <iostream>
#include <set>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> ans;
        int a;
        for(int i=0; i<n; i++){
            cin >> a;
            ans.insert(a);
        }
        cout << ans.size() << endl;
    }
}