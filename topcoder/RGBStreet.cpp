#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

class RGBStreet {

private:
    vector<vector<int>> rgbs;
    vector<vector<int>> dp;
    static vector<int> extractIntegerWords(const string& str){
        stringstream ss(str);
        string temp;
        int found;
        vector<int> integers;
        while (!ss.eof()) {
            ss >> temp;
            if (stringstream(temp) >> found)
                integers.push_back(found);
            temp = "";
        }
        return integers;
    }

    int solve(int pos, int c){
        if(pos == rgbs.size()-1) return this->rgbs[pos][c];
        if(dp[pos][c] != -1) return dp[pos][c];
        int a = numeric_limits<int>::max();
        for(int i=0; i<3; i++){
            if(i != c)
                a = min(a, solve(pos+1, i));
        }
        return dp[pos][c] = a + rgbs[pos][c];
    }

public:
    int estimateCost(const vector<string>& houses){
        for(const auto& rgb : houses)
            this->rgbs.emplace_back(this->extractIntegerWords(rgb));
        dp.assign(houses.size(), vector<int>(3, -1));
        return min(solve(0, 2), min(solve(0, 0), solve(0, 1)));
    }
};