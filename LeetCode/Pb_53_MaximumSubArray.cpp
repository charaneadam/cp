#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums) {
    // Maximum contiguous subarray sum (should contain at least one element
    bool allneg = true;
    for(auto n : nums) if(n >= 0) allneg = false;
    if(allneg){
        int mx = nums[0];
        for(auto n : nums) mx = max(mx, n);
        return mx;
    }
    int n = (int) nums.size();
    int ans = 0;
    int res = ans;
    for (int j = 1; j <= n; j++) {
        ans = max(ans + nums[j - 1], nums[j - 1]);
        res = max(res, ans);
    }
    return res;
}

int main(){
    vector<int> nums = {-1};
    assert(maxSubArray(nums) == -1);
    nums = {-2,1,-3,4,-1,2,1,-5,4};
    assert(maxSubArray(nums) == 6);
    return 0;
}