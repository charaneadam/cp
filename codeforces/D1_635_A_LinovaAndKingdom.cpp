#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph{
private:
    int num_nodes;
    vector<vector<int>> adjacencyList;
    vector<bool> _visited;
    vector<int> _depth;
    vector<int> _rev_depth;

public:
    explicit Graph(int numNodes) : num_nodes(numNodes) {
        this->adjacencyList.assign(numNodes+1, vector<int>());
        this->_visited.assign(numNodes+1, false);
        this->_depth.assign(numNodes+1, 0);
        this->_rev_depth.assign(numNodes+1, 0);
    }

    void add_edge(int node1, int node2){
        this->adjacencyList[node1].push_back(node2);
        this->adjacencyList[node2].push_back(node1);
    }

    long long dfs(int source, int depth){
        _visited[source] = true;
        _depth[source] = depth;
        long long ret = 0;
        for(auto adjacent : this->adjacencyList[source]){
            if(!_visited[adjacent]){
                ret += 1 + dfs(adjacent, depth+1);
            }
        }
        _rev_depth[source] = ret;
        return ret;
    }

    long long solve(int k, int source = 1){
        dfs(source,0);
        vector<int> nodes(num_nodes);
        for(int i=0; i<num_nodes; i++)
            nodes[i] = _depth[i+1] - _rev_depth[i+1];
        sort(nodes.begin(), nodes.end(), greater<>());
        long long ans = 0;
        for(int i=0; i<k; i++)
            ans += nodes[i];
        return ans;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    int a,b;
    Graph graph(n);
    while(--n){
        cin >> a >> b;
        graph.add_edge(a, b);
    }
    cout << graph.solve(k);
    return 0;
}