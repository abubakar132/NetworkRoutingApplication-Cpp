// Graph.cpp
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "ANSI.h"
#include <iostream>

Graph::Graph() {}

Graph::~Graph() {
    for (auto vertex : vertices) {
        delete vertex;
    }
    for (auto edge : edges) {
        delete edge;
    }
}

void Graph::addVertex(int id) {
    vertices.push_back(new Vertex(id));
}

void Graph::addEdge(Vertex* start, Vertex* end, int weight) {
    edges.push_back(new Edge(start, end, weight));
}

void Graph::printGraph() {
    std::cout <<GREEN<< "\nNetwork Topology:\n";
    for (size_t i = 0; i < edges.size(); ++i) {
        Edge* edge = edges[i];
        std::cout <<GREEN<< "Connection: " << edge->start->id << " - " << edge->end->id << " Weight/Cost: " << edge->weight << "\n";
    }
    std::cout << std::endl;
}
