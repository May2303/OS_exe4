#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "eulerian.hpp"

void generateRandomGraph(Graph& g, int edges) {
    int vertices = g.getNumVertices();
    srand(time(nullptr));
    
    for (int i = 0; i < edges; ++i) {
        int src = rand() % vertices;
        int dest = rand() % vertices;
        if (src != dest) {
            g.addEdge(src, dest);
        }
    }
}

int main(int argc, char* argv[]) {
    int numVertices = 0;
    int numEdges = 0;
    int seed = time(nullptr);

    int opt;
    while ((opt = getopt(argc, argv, "v:e:s:")) != -1) {
        switch (opt) {
            case 'v':
                numVertices = atoi(optarg);
                break;
            case 'e':
                numEdges = atoi(optarg);
                break;
            case 's':
                seed = atoi(optarg);
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " -v numVertices -e numEdges -s seed\n";
                return 1;
        }
    }

    if (numVertices <= 0 || numEdges < 0) {
        std::cerr << "Invalid number of vertices or edges.\n";
        return 1;
    }

    srand(seed);

    Graph g(numVertices);
    generateRandomGraph(g, numEdges);

    std::cout << "Generated Graph:\n";
    g.printGraph();

    Eulerian eulerian(g);
    if (eulerian.hasEulerianCircuit()) {
        std::cout << "The graph has an Eulerian circuit.\n";
    } else {
        std::cout << "The graph does not have an Eulerian circuit.\n";
    }

    return 0;
}
