
#include "GraphUsingAdjacencyLists.h"

GraphUsingAdjacencyLists::GraphUsingAdjacencyLists(int V) {
    adjacencyLists.resize(V);
}

GraphUsingAdjacencyLists::GraphUsingAdjacencyLists(std::istream& s) {
    int V,E,v,w;
    
    s >> V;
    s >> E;
    
    adjacencyLists.resize(V);
    
    for (int i = 0; i < E; i++) {
        s >> v;
        s >> w;
        addEdge(v, w);
    }
}

void GraphUsingAdjacencyLists::addEdge(int v, int w) {
    adjacencyLists.at(v).push_back(w);
    if (v != w)
        adjacencyLists.at(w).push_back(v);
}

GraphUsingAdjacencyLists::Iterable GraphUsingAdjacencyLists::adjacent(int v) const {
    return adjacencyLists.at(v);
}

int GraphUsingAdjacencyLists::V() const {
    return (int) adjacencyLists.size();
}
