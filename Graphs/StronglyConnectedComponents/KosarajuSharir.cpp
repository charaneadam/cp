#include <bits/stdc++.h>

using namespace std;

#define MAX_N 20001

int n, m;
struct Node {
    vector<int> adj;
    vector<int> rev_adj;
};
Node graph[MAX_N];

stack<int> S;
bool visited[MAX_N];

int component[MAX_N];
vector<int> components[MAX_N];
int numComponents;

void PushPostRevDFS(int x) {
    visited[x] = true;
    for (int i : graph[x].adj) {
        if (!visited[i]) PushPostRevDFS(i);
    }
    S.push(x);
}

void LabelOneDFS(int x) {
    cout << x << ' ';
    component[x] = numComponents;
    components[numComponents].push_back(x);
    visited[x] = true;
    for (int i : graph[x].rev_adj) {
        if (!visited[i]) LabelOneDFS(i);
    }
}

void KosarajuSharir() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) PushPostRevDFS(i);
    }

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    while (!S.empty()) {
        int v = S.top();
        S.pop();
        if (!visited[v]) {
            cout << "Component " << numComponents << ": ";
            LabelOneDFS(v);
            numComponents++;
            cout << endl;
        }
    }
}

int main() {
    cin >> n >> m;
    int u,v;
    for(int _=0; _<m; _++){
        cin >> u >> v;
        u--;
        v--;
        graph[u].adj.push_back(v);
        graph[v].rev_adj.push_back(u);
    }

    KosarajuSharir();

    cout << "Total number of components: " << numComponents << endl;

    return 0;
}