// main.cpp

#include "Graph.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "ANSI.h"
#include <iostream>

using namespace std;
int main() {
    // Create a graph
    Graph graph;
    cout<<YELLOW<<"***************************************************************\n -----------------Network Routing Algorithm-------------------\n***************************************************************\n\n";
    // Take input for the number of vertices
    int numVertices;
    cout <<CYAN<<"Enter the number of Devices: ";
    cin >> numVertices;

    // Add vertices
    for (int i = 1; i <= numVertices; ++i) {
        graph.addVertex(i);
    }

    // Take input for the number of edges
    int numEdges;
    cout <<CYAN<< "Enter the number of connections: ";
    cin >> numEdges;

    // Add edges with weights
    for (int i = 0; i < numEdges; ++i) {
        int startVertex, endVertex, weight;
        cout <<CYAN<< "Enter starting device, ending device, and weight/cost for connection " << i + 1 << ": ";
        cin >> startVertex >> endVertex >> weight;
        cin.ignore();

        // Add edges to the graph
        graph.addEdge(graph.vertices[startVertex - 1], graph.vertices[endVertex - 1], weight);
    }
    // Print the graph
    graph.printGraph();

    // Take input for the source vertex
    int sourceVertex;
    cout <<CYAN<< "\nEnter the source vertex for Routing algorithm: ";
    cin >> sourceVertex;
    //Label for goto statement
    selection:
    //Initialization of Flag for detecting negative edges while applying Dijkstra
    bool negativeflag=false;
    // Choose the routing algorithm
    int choice;
    cout <<CYAN<< "Choose the routing algorithm:\n";
    cout <<CYAN<< "1. Dijkstra's Algorithm\n";
    cout <<CYAN<< "2. Bellman-Ford Algorithm\n";
    cout <<CYAN<< "Enter your choice (1 or 2): ";
    cin >> choice;
    cout<<endl;

    Vertex* source = graph.vertices[sourceVertex - 1];

    // Apply the selected algorithm
    if (choice == 1) {
        Dijkstra::shortestPath(graph, source, negativeflag);
        if(negativeflag)
            goto selection;
    } else if (choice == 2) {
        BellmanFord::shortestPath(graph, source);
    } else {
        cout <<RED<< "Invalid choice. Exiting.\n";
        return 1;
    }

    return 0;

}


