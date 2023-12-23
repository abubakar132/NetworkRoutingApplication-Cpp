// Dijkstra.h
#pragma once
#include <vector>
#include "Graph.h"
class Dijkstra {
public:
    static void shortestPath(Graph& graph, Vertex* source, bool& negativeflag);
};
