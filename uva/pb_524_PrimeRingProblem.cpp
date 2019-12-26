#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> primes;
int sol[20];
vector<bool> taken;

void printSol(){
    for(int j=0; j<n; j++){
        cout << sol[j];
        if(j != n-1) cout << ' ';
    }
    cout << endl;
}

void solve(int p){
    if(p == n){
        if(binary_search(primes.begin(), primes.end(), 1 + sol[n-1]))
            printSol();
        return;
    }
    int prev = sol[p-1];
    for(int r = 2; r<=n; r++){
        if(taken[r]) continue;
        if(binary_search(primes.begin(), primes.end(), prev+r)){
            sol[p] = r;
            taken[r] = true;
            solve(p+1);
            taken[r] = false;
        }
    }
}

int main(){
    primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    sol[0] = 1;
    int tc = 0;
    while(cin >> n){
        if(tc++) cout << endl;
        cout << "Case " << tc << ": " << endl;
        taken.assign(20, false);
        taken[1] = true;
        if(n > 1){
            solve(1);
        }
    }
    return 0;
}