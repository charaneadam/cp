#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> t;
/*
0 0 1 0 1 1 0 0 0 1 0 1
0 0 1
*/

int solve(int pos, int ind){
    if(pos == n) return 1;
    int a,b;
    if(t[pos]){
        a = solve(pos+1, 1);
    }
    else{
        if(ind){
            b = solve(pos+1, 0);

        }
    }
}

int main(){
    cin >> n;
    t.assign(n, 0);
    char c;
    for(int i=0; i<n; i++){
        cin >> c;
        if(c == 'f') t[i] = 1;
    }
    cout << solve(0, 0);
}