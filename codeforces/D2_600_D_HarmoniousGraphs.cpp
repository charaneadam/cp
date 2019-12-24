#include <bits/stdc++.h>
using namespace std;

void dfs(int s, int &mn, int &mx, vector<vector<int>> &graph, vector<bool> &vis){
    vis[s] = true;
    mn = min(mn, s);
    mx = max(mx, s);
    for(auto node : graph[s]){
        if(!vis[node]){
            dfs(node, mn, mx, graph, vis);
        }
    }
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<bool> vis(n+1, false);
    for(int _=0; _<m; _++){
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<pair<int, int>> cc;
    for(int node = 1; node <= n; node++){
        if(!vis[node]){
            int mn = node;
            int mx = node;
            dfs(node, mn, mx, graph, vis);
            pair<int, int> minmax = {mn, mx};
            cc.emplace_back(minmax);
        }
    }
    int curr_end = -1;
    int ans = 0;
    for(auto c : cc){
        if(c.first <= curr_end){
            ans++;
        }
        curr_end = max(curr_end, c.second);
    }
    cout << ans;
    return 0;
}