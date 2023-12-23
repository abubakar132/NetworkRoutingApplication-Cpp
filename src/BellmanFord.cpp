// BellmanFord.cpp
#include "BellmanFord.h"
#include "Graph.h"
#include "ANSI.h"
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>  // For std::min

void BellmanFord::shortestPath(Graph& graph, Vertex* source) {
    // Get the number of vertices in the graph
    size_t numVertices = graph.vertices.size();

    // Initialize distances to all vertices as infinite
    std::vector<int> distances(numVertices, INT_MAX);

    // Mark the source vertex with distance 0
    distances[source->id - 1] = 0;

    // Relax edges repeatedly (V - 1) times
    for (size_t i = 1; i < numVertices; ++i) {
        for (const Edge* edge : graph.edges) {
            int u = edge->start->id - 1;
            int v = edge->end->id - 1;
            int weight = edge->weight;

            // Relax the edge
            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const Edge* edge : graph.edges) {
        int u = edge->start->id - 1;
        int v = edge->end->id - 1;
        int weight = edge->weight;

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            std::cout <<RED<< "Graph contains negative-weight cycle. Bellman-Ford does not work in this case.\n";
            return;
        }
    }

    // Print the result
    std::cout <<YELLOW<< "\nShortest paths from vertex " << source->id << " using Bellman-Ford:\n";
    for (size_t i = 0; i < numVertices; ++i) {
        if (i != source->id - 1) {
            if (distances[i] == INT_MAX) {
                std::cout <<YELLOW<< "Vertex " << i + 1 <<RED<< ": Not reachable\n";
            } else {
                std::cout <<YELLOW<< "Vertex " << i + 1 << ": Distance = " << distances[i] << "\n";
            }
        }
    }
}
