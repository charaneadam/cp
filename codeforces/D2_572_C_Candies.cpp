#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1189/C

class Candies{
private:
    vector<int> tree, nums;
    int n;
    void build(int p, int l, int r){
        if(l == r){
            tree[p] = nums[l];
        }
        else{
            int left = p*2;
            int right = left + 1;
            int mid = (l+r)/2;
            build(left, l, mid);
            build(right, mid + 1, r);
            int ans = tree[left] + tree[right];
            tree[p] = ans;
        }
    }
    int rsq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return 0;
        if (L >= i && R <= j) return tree[p];

        int left = p * 2;
        int right = left + 1;
        int mid = (L + R) / 2;
        int p1 = rsq(left, L, mid, i, j);
        int p2 = rsq(right, mid + 1, R, i, j);

        return p1 + p2;
    }
public:
    Candies(const vector<int> &s){
        this->n = (int)s.size();
        this->nums = s;
        this->tree.assign(4*n+1, 0);
        this->build(1, 0, n-1);
    }
    int rsq(int i, int j){
        return rsq(1, 0, n - 1, i-1, j-1);
    }
};

int solve(int i, int j, vector<int> &nums){
    return nums[j] - nums[i - 1];
}

int main(){
    int n,q,a=1,b;
    cin >> n;
    vector<int> s(n), nums(n+1, 0);
    for(auto &num : s){
        cin >> num;
        nums[a] += nums[a-1] + num;
        a++;
    }
    Candies can = * new Candies(s);
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << can.rsq(a, b) / 10<< endl;
//        cout << solve(a, b, nums) / 10 << endl;
    }
    return 0;
}