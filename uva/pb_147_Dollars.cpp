#include <bits/stdc++.h>

using namespace std;

vector<int> p = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
const int n = (int)p.size();
vector<vector<long long>> dp(n+5, vector<long long>(30000+5, -1));

long long solve(int amount, int pos = 0){
    long long &ans = dp[pos][amount];
    if(pos == n) return ans = 0;
    if(!amount) return ans = 1;
    if(ans != -1) return ans;#include <bits/stdc++.h>

using namespace std;

vector<int> p = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
const int n = (int)p.size();
vector<vector<long long>> dp(n+5, vector<long long>(30000+5, -1));

long long solve(int amount, int pos = 0){
    long long &ans = dp[pos][amount];
    if(pos == n) return ans = 0;
    if(!amount) return ans = 1;
    if(ans != -1) return ans;
    long long a,b=0;
    a = solve(amount, pos+1);
    if(p[pos] <= amount)
        b = solve(amount - p[pos], pos);
    return ans = a + b;
}

void print_output(double amount, long long ans){
    cout << setw(6);
    cout << fixed << setprecision(2) << amount;
    cout << setw(17);
    cout << ans << endl;
}

int main(){
    double amount;
    while(cin >> amount && amount != 0.00){
        print_output(amount, solve((int)(100*amount)));
    }
}
    long long a,b=0;
    a = solve(amount, pos+1);
    if(p[pos] <= amount)
        b = solve(amount - p[pos], pos);
    return ans = a + b;
}

void print_output(double amount, long long ans){
    cout << setw(6);
    cout << fixed << setprecision(2) << amount;
    cout << setw(17);
    cout << ans << endl;
}

int main(){
    double amount;
    while(cin >> amount && amount != 0.00){
        print_output(amount, solve((int)(100*amount)));
    }
}