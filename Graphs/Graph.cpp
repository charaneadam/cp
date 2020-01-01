//
// Created by adam on 1/2/20.
//

#include "Graph.h"

#include <utility>

Graph::Graph(int n) {
    this->n_nodes = n;
    this->graph.assign(n+1, set<int>());
}

Graph::Graph(int n, vector<edge> &edges) : Graph(n) {
    for(auto edge : edges){
        this->add_edge(edge);
    }
}

void Graph::add_edge(edge e) {
    this->edges.insert(e);
    this->graph[e.first].insert(e.second);
    this->graph[e.second].insert(e.first);
}

void Graph::remove_edge(edge e) {
    this->edges.erase(e);
    this->graph[e.first].erase(e.second);
    this->graph[e.second].erase(e.first);
}

int Graph::number_edges() {
    return this->edges.size();
}
