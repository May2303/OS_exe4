#ifndef EULERIAN_H
#define EULERIAN_H

#include "graph.hpp"

class Eulerian {
public:
    Eulerian(const Graph& g);
    bool hasEulerianCircuit() const;

private:
    bool isConnected() const;
    const Graph& graph;
    mutable std::vector<bool> visited;
    mutable std::vector<int> degree;
};

#endif // EULERIAN_H
