#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <limits>

using namespace std;

typedef vector<vector<int>> Tree;
typedef pair<int, long long> Query;

vector<long long> power;
Tree tree;
map<int, vector<long long>> queried;
map<Query, int> answered;

int solve(int p, vector<long long> &cur_pwr, vector<int> &cur_ppl){
    cur_pwr.push_back(power[p]);
    cur_ppl.push_back(p);
    if(queried.count(p)){
        for(auto pwr : queried[p]){
            int pers = (int)cur_ppl.size()-1;
            if(pwr > cur_pwr[pers]) answered[make_pair(p, pwr)] = -1;
            else{
                while(pers > 0){
                    if(cur_pwr[pers-1] >= pwr) pers--;
                    else break;
                }
                answered[make_pair(p, pwr)] = (pers != (int)cur_ppl.size()-1 ? pers : -1);
            }
        }
    }
    for(auto child : tree[p])
        solve(child, cur_pwr, cur_ppl);
    cur_pwr.pop_back();
    cur_ppl.pop_back();
    return 0;
}


int main() {
    int n, q;
//    while (cin >> n >> q) {
        cin >> n >> q;
        tree.assign(n, vector<int>());
        power.assign(n, 0LL);
        int pr;
        long long lvl;
        vector<bool> is_root(n, true);
        int root = -1;
        for(int i=1; i<=n-1; i++){
            cin >> pr >> lvl;
            tree[pr].emplace_back(i);
            is_root[i] = false;
            power[i] = lvl;
        }
        for(int i=0; i<n-1 && root == -1; i++)
            if(is_root[i])
                root = i;
        if(root < 0) cerr << "Error: Can't find root" << endl;
        vector<Query> queries(q);
        for(int i=0; i<q; i++){
            cin >> queries[i].first >> queries[i].second;
            queried[queries[i].first].emplace_back(queries[i].second);
        }
        vector<long long> cur_pwr;
        vector<int> cur_ppl;
        cout << solve(root, cur_pwr, cur_ppl) << endl;
        for(auto que : queries){
            cout << answered[que] << endl;
        }
//    }
    return 0;
}