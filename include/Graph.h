// Graph.h
#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
class Graph {
public:
    Graph();
    ~Graph();

    void addVertex(int id);
    void addEdge(Vertex* start, Vertex* end, int weight);
    void printGraph();
    std::vector<Vertex*> vertices;
    std::vector<Edge*> edges;
private:

};
