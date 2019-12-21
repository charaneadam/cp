#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

class MaximalProduct {

private:
    int maxK;
    vector<vector<long long>> dp;
    long long solve(int k, int rem){
        if(k == maxK)
            if(rem) return 0;
            else return 1;
        if(!rem) return 0;
        long long &saved_ans = dp[k][rem];
        if(saved_ans) return saved_ans;
        long long ans = 0;
        for(int i=1; i<=rem; i++){
            long long a = solve(k+1, rem-i) * i;
            ans = max(ans, a);
        }
        return saved_ans = ans;
    }

public:
    long long maximalProduct(int s, int k){
        this->maxK = k;
        dp.assign(k, vector<long long>(s+1, 0LL));
        return solve(0, s);
    }
};