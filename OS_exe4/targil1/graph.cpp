#include "graph.hpp"
#include <iostream>

Graph::Graph(int vertices) : numVertices(vertices), adjLists(vertices) {}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src); // For undirected graph
}

void Graph::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ":";
        for (int v : adjLists[i]) {
            std::cout << " -> " << v;
        }
        std::cout << std::endl;
    }
}

int Graph::getNumVertices() const {
    return numVertices;
}

const std::vector<std::list<int>>& Graph::getAdjLists() const {
    return adjLists;
}
