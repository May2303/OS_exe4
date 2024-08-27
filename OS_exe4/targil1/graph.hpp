#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void printGraph() const;
    int getNumVertices() const;
    const std::vector<std::list<int>>& getAdjLists() const;

private:
    int numVertices;
    std::vector<std::list<int>> adjLists;
};

#endif // GRAPH_H
