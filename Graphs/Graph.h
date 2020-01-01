//
// Created by adam on 1/2/20.
//

#ifndef CP_GRAPH_H
#define CP_GRAPH_H

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge;


class Graph {

private:
    int n_nodes;
    set<edge> edges;
    vector<set<int>> graph;
public:
    explicit Graph(int);
    Graph(int n, vector<edge> &edges);
    void add_edge(edge);
    void remove_edge(edge);
    int number_edges();
};


#endif //CP_GRAPH_H
