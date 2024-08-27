#include "eulerian.hpp"
#include <vector>

Eulerian::Eulerian(const Graph& g) : graph(g), visited(g.getNumVertices(), false), degree(g.getNumVertices(), 0) {
    const auto& adjLists = g.getAdjLists();
    for (int i = 0; i < g.getNumVertices(); ++i) {
        for (int v : adjLists[i]) {
            degree[i]++;
        }
    }
}

bool Eulerian::isConnected() const {
    std::vector<bool> localVisited(graph.getNumVertices(), false);

    auto DFS = [&](int vertex, auto&& DFSRef) -> void {
        localVisited[vertex] = true;
        for (int v : graph.getAdjLists()[vertex]) {
            if (!localVisited[v]) {
                DFSRef(v, DFSRef);
            }
        }
    };

    int startVertex = 0;
    while (startVertex < graph.getNumVertices() && graph.getAdjLists()[startVertex].empty()) {
        startVertex++;
    }

    if (startVertex == graph.getNumVertices()) return true;

    DFS(startVertex, DFS);

    for (int i = 0; i < graph.getNumVertices(); ++i) {
        if (!graph.getAdjLists()[i].empty() && !localVisited[i]) {
            return false;
        }
    }
    return true;
}

bool Eulerian::hasEulerianCircuit() const {
    if (!isConnected()) return false;

    for (int i = 0; i < graph.getNumVertices(); ++i) {
        if (degree[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}
