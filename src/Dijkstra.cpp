// Dijkstra.cpp
#include "Dijkstra.h"
#include "Graph.h"
#include "ANSI.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

void Dijkstra::shortestPath(Graph& graph, Vertex* source, bool& negativeflag) {
    // Check for negative edges
    for (Edge* edge : graph.edges) {
        if (edge->weight < 0) {
            std::cout <<RED<< "Negative weight detected. Dijkstra should not be applied. Please choose Bellman-Ford algorithm.\n";
            negativeflag = true;
            return;
        }
    }

    // Initialize distances to all vertices as infinite
    std::vector<int> distances(graph.vertices.size(), INT_MAX);

    // Mark the source vertex with distance 0
    distances[source->id - 1] = 0;

    // Priority queue to store vertices and their distances
    std::priority_queue<std::pair<int, Vertex*>, std::vector<std::pair<int, Vertex*>>, std::greater<std::pair<int, Vertex*>>> pq;

    pq.push({0, source});

    // Map to store the next hop for each vertex
    std::unordered_map<int, Vertex*> nextHop;

    while (!pq.empty()) {
        Vertex* currentVertex = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        // Iterate over adjacent vertices of the current vertex
        for (Edge* edge : graph.edges) {
            if (edge->start == currentVertex) {
                int newDistance = currentDistance + edge->weight;

                // Update distance if a shorter path is found
                if (newDistance < distances[edge->end->id - 1]) {
                    distances[edge->end->id - 1] = newDistance;
                    pq.push({newDistance, edge->end});

                    // Update next hop
                    nextHop[edge->end->id] = currentVertex;
                }
            }
        }
    }

    // Print the result
    std::cout <<YELLOW<< "\nShortest paths from Device " << source->id << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        if (i + 1 != source->id) {
            if (distances[i] == INT_MAX) {
                std::cout <<YELLOW<< "Device " << i + 1 <<RED<< ": Not reachable\n";
            } else {
                std::cout <<YELLOW<< "Device " << i + 1 << ": Distance = " << distances[i];

                // Print the shortest path
                std::cout <<YELLOW<< ", Shortest Path: " << source->id;
                Vertex* next = nextHop[i + 1];
                while (next) {
                    std::cout << " -> " << next->id;
                    next = nextHop[next->id];
                }

                std::cout << "\n";
            }
        }
    }
}
