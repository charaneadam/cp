#include <bits/stdc++.h>

using namespace std;

void dfs(int s, vector<vector<int>> &g, vector<bool> &visited, unordered_set<int> &elems){
    elems.insert(s);
    visited[s] = true;
    for(auto adj : g[s])
        if(!visited[adj])
            dfs(adj, g, visited, elems);
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n+1, vector<int>());
    vector<unordered_set<int>> components;
    vector<bool> visited(n+1, false);
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            unordered_set<int> elems;
            dfs(i, g, visited, elems);
            components.push_back(elems);
        }
    }

    int ans = 0;
    for(const auto& comp : components){
        int comp_ans = 0;
        for(auto node : comp)
            comp_ans += g[node].size();
        ans = max(ans, comp_ans/2);
    }

    cout << ans;
}