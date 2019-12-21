#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <sstream>
#include <limits>
#include <cassert>

using namespace std;

class TriviaGame {

private:
    vector <int> p,b;
    int t;
    vector<vector<int>> dp;
    int solve(int pos, int tokens){
        if(pos == this->p.size()) return 0;
        int &ans = this->dp[pos][tokens];
        if(ans != -1)
            return ans;
        int a = solve(pos+1, tokens) - this->p[pos];
        int b = 0;
        if(tokens + 1 == this->t){
            b = solve(pos+1, 0) + this->p[pos] + this->b[pos];
        }
        else{
            b = solve(pos+1, tokens+1) + this->p[pos];
        };
        return ans = max(a, b);
    }

public:
    int maximumScore(vector <int> points, int tokensNeeded, vector <int> bonuses){
        this->p = std::move(points);
        this->b = std::move(bonuses);
        this->t = tokensNeeded;
        this->dp.assign(this->p.size()+2, vector<int>(tokensNeeded+2, -1));
        return solve(0, 0);
    }
};

int main(){
    TriviaGame solver;
    assert(solver.maximumScore({1, 2, 3, 4, 5, 6}, 3, {4, 4, 4, 4, 4, 4}) == 29);
    assert(solver.maximumScore({1, 2, 3, 4, 5, 6}, 3, {1, 1, 1, 20, 1, 1}) == 39);
    assert(solver.maximumScore({150, 20, 30, 40, 50}, 3, {0, 0, 0, 250, 0}) == 500);
    assert(solver.maximumScore({500, 500, 500, 0, 500}, 3, {0, 0, 0, 500, 0}) == 2000);
    return 0;
}