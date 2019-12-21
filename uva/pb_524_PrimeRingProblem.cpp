#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;

int n;
set<int> rem, primes;
vector<int> sol;

void printSol(){
    for(int i=0; i<n; i++){
        cout << sol[i];
        if(i<n-1) cout << ' ';
    }
    cout << endl;
}

void solve(int p){
    if(p == n){
        printSol();
    }
    else{
        for(auto num : rem){
            if(p == n-1){
                if(primes.count(num + 1) && primes.count(num + sol[p-1])){
                    sol.emplace_back(num);
                    rem.erase(num);
                    solve(p+1);
                    rem.insert(num);
                    sol.pop_back();
                }
            }
            else if(primes.count(num + sol[p-1])){
                sol.emplace_back(num);
                rem.erase(num);
                solve(p+1);
                rem.insert(num);
                sol.pop_back();
            }
        }
    }
}

int main(){
    primes = {2,3,5,7,11,13,17,19,23,29,31};
    sol.emplace_back(1);
    while(cin >> n){
        for(int i=2; i<=n; i++) rem.insert(i);
        solve(1);
        rem.clear();
    }
    return 0;
}