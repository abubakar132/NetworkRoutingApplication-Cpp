// Edge.h
#pragma once
#include "Vertex.h"
class Edge {
public:
    Vertex* start;
    Vertex* end;
    int weight;

    Edge(Vertex* start, Vertex* end, int weight);
};
