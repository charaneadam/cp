#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// WA :(
class Box{
private:
    int id;
    int n;
    vector<int> dims;
public:
    explicit Box(int dimension, vector<int> &dimensions, int id){
        this->n = dimension;
        sort(dimensions.begin(), dimensions.end());
        this->dims = dimensions;
        this->id = id;
    }

    bool operator < (Box const &other_box){
        bool less = true;
        for(int d=0; d < this->n && less; d++)
            if(other_box.dims[d] <= this->dims[d])
                less = false;
        return less;
    }

    int get_id(){
        return this->id;
    }
};

vector<Box> boxes;
int k;
vector<vector<int>> graph;
vector<bool> vis;

int dfs(int s){
    vis[s] = true;
    int l = 1;
    for(auto c : graph[s]){
        if(!vis[c]){
            l += dfs(c);
        }
    }
    return l;
}


int main(){
    int n;
    while(cin >> k >> n){
        for(int i=0; i<k; i++){
            vector<int> b(n);
            for(int j=0; j<n; j++) cin >> b[j];
            Box box(n, b, i+1);
            boxes.emplace_back(box);
        }
        sort(boxes.begin(), boxes.end());
        graph.assign(k+5, vector<int>());
        vis.assign(k+1, false);
        for(int i=0; i<k-1; i++){
            for(int j=i+1; j<k; j++){
                if(boxes[i] < boxes[j])
                    graph[boxes[i].get_id()].emplace_back(boxes[j].get_id());
            }
        }
        int ans = 0;
        for(int i=0; i<k; i++){
            if(!vis[i])
                ans = max(ans, dfs(i));
        }
        cout << ans << endl;
    }
    return 0;
}