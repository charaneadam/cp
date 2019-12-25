#include <bits/stdc++.h>
using namespace std;

class Sol1{
    // TLE !!
private:
    unordered_set<int> _sums;
    vector<int> sums;

    void generate_all_possible_sums(const vector<vector<int>> &t, int i=0, int sum=0){
        if(i == t.size()){
            if(_sums.find(sum) == _sums.end()){
                _sums.insert(sum);
                sums.push_back(sum);
            }
            return;
        }
        for(auto num : t[i]){
            generate_all_possible_sums(t, i+1, sum + num);
        }
    }

public:
    void run(){
        int tc;
        cin >> tc;
        while(tc--){
            int m, c;
            cin >> m >> c;
            vector<vector<int>> t(c);
            vector<int> pos(c, 0);
            for(int i=0,k,a; i<c; i++){
                cin >> k;
                for(int j=0; j<k; j++){
                    cin >> a;
                    t[i].push_back(a);
                }
            }
            generate_all_possible_sums(t);
            sort(sums.begin(), sums.end());
            int idx = (lower_bound(sums.begin(), sums.end(), m) - sums.begin());
            idx--;
            if(idx + 1) cout << sums[idx] << endl;
            else cout << "no solution" << endl;
            sums.clear();
            _sums.clear();
        }
    }
};

class Sol2{
    // WA
public:
void run(){
    int tc;
    cin >> tc;
    while(tc--){
        int m, c;
        cin >> m >> c;
        vector<vector<int>> t(c);
        vector<int> ans(m+1, -1);
        for (int i = 0, k, a; i < c; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> a;
                t[i].push_back(a);
            }
            sort(t[i].begin(), t[i].end());
        }
        int min_sum = 0;
        for(const auto &gs : t)
            min_sum += gs[0];
        int sum, new_sum;
        for(int amount = 0; amount < m+1; amount++){
            sum = min_sum;
            for(int j=0; j<c; j++){
                for(int k=0; k<t[j].size() - 1; k++){
                    new_sum = sum - t[j][k] + t[j][k+1];
                    if(amount >= new_sum && new_sum > sum){
                        sum = new_sum;
                    }
                }
            }
            if(amount >= sum)
                ans[amount] = sum;
        }
        if(ans[m] + 1)
            cout << ans[m] << endl;
        else cout << "no solution" << endl;
    }
}

};

class Sol3{
    // AC
private:
    int m, c;
    vector<vector<int>> t;
    vector<vector<int>> dp;
    void read_input(){
        cin >> m >> c;
        t.assign(c, vector<int>());
        dp.assign(m+1, vector<int>(c, -1));
        for (int i = 0, k, a; i < c; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> a;
                t[i].push_back(a);
            }
        }
    }

    int solve(int amount, int i=0){
        if(amount < 0) return numeric_limits<int>::min();
        if(i == c){
            return m - amount;
        }
        int &ans = dp[amount][i];
        if(ans != -1) return ans;
        for(auto s : t[i]){
            int a = solve(amount - s, i+1);
            ans = max(ans, a);
        }
        return ans;
    }


public:
    void run(){
        int tc;
        cin >> tc;
        while(tc--){
            read_input();
            int sol = solve(m);
            if(sol > 0) cout << sol;
            else cout << "no solution";
            cout << endl;
        }
    }
};

class Sol4{
    //Shall I go with a bottom up solution this time ?!
};

int main(){
    Sol3 s;
    s.run();
    return 0;
}