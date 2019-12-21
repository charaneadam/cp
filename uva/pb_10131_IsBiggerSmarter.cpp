#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;

int n;
vector<pair<pair<int, int>, int>> elephants;
vector<vector<pair<int, int>>> dp;
vector<vector<int>> sol;

bool _sort_helper(pair<int, int> a, pair<int, int> b){
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}

bool sort_helper(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return _sort_helper(a.first, b.first);
}

vector<int> findLIS(vector<int> arr){
    int arr_sz = (int)arr.size();
    vector<int> LIS[arr_sz];
    LIS[0].push_back(arr[0]);
    for (int i = 1; i < arr_sz; i++){
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
                LIS[i] = LIS[j];
        }
        LIS[i].push_back(arr[i]);
    }
    int j = 0;
    for (int i = 0; i < arr_sz; i++)
        if (LIS[j].size() < LIS[i].size())
            j = i;
    vector<int> ans;
    for (int i : LIS[j])
        ans.emplace_back(i);
    return ans;
}

int solve(int pos, int last){
    if(pos == n)
        return 0;
    int &ans = dp[pos][last].first;
    int &idx = dp[pos][last].second;
    if(pos == n-1){
//        idx = last;
        return ans = 1;
    }
    if(ans != -1) return ans;
    int a = solve(pos+1, last);
    int b = 0;
    if(last == n || (elephants[pos].second < elephants[pos+1].second && elephants[pos].first > elephants[pos+1].first))
        b = 1 + solve(pos+1, pos);

    idx = min(idx, elephants[pos].second);
    ans = max(a, b);
    return ans;
}

int main(){
    cin >> n;
    int w,i;
    int idx = 1;
    while(n--){
        cin >> w >> i;
        elephants.emplace_back(make_pair(make_pair(w, i), idx++));
    }
    sort(elephants.begin(), elephants.end(), sort_helper);
//    for(auto e : elephants) cout << e.first.first << ' ' << e.first.second << ' '  << e.second << endl;
    n = (int)elephants.size();
    dp.assign(n+1, vector<pair<int, int>>(n+1, make_pair(-1, numeric_limits<int>::max())));
    sol.assign(n+1, vector<int>(n+1, -1));
    cout << solve(0, n) << endl;
    for(auto c : dp){
        for(auto cc : c)
            cout << '{' << cc.first << ' ' << cc.second << "}, ";
        cout << endl;
    }
//    for(auto e : sol) cout << e << ' ';

    return 0;
}