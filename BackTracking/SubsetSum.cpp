#include <bits/stdc++.h>
using namespace std;

bool solve(int rem, vector<int> &nums, int pos = 0){
    if(rem == 0) return true;
    if(pos == nums.size()) return false;
    bool a=false,b;
    if(rem >= nums[pos]){
        a = solve(rem - nums[pos], nums, pos+1);
    }
    b = solve(rem, nums, pos+1);
    return a || b;
}

int main(){
    vector<int> X = {8, 6, 7, 5, 3, 10, 9};
    int T = 15;
    assert(solve(T, X));
    X = {11, 6, 5, 1, 7, 13, 12};
    assert(!solve(T, X));
}