#include <iostream>
#include "Graph.cpp"

using namespace std;

int main() {
    Graph metroMap; 

    // Add vertices (stations) to the metro map
    metroMap.addVertex("Station A");
    metroMap.addVertex("Station B");
    metroMap.addVertex("Station C");
    metroMap.addVertex("Station D");
    metroMap.addVertex("Station E");

    // Add edges (connections between stations) to the metro map
    metroMap.addEdge("Station A", "Station B", 5);
    metroMap.addEdge("Station A", "Station C", 10);
    metroMap.addEdge("Station B", "Station D", 15);
    metroMap.addEdge("Station C", "Station D", 20);
    metroMap.addEdge("Station D", "Station E", 25);

    // Display the metro map
    metroMap.displayMap();

    // Perform Dijkstra's algorithm to find the shortest path between two stations
    string source = "Station A";
    string destination = "Station E";
    unordered_map<string,bool> proc;
    bool hasPath = metroMap.hasPath(source, destination, proc);

    if (hasPath) {
        int shortestDistance = metroMap.dijkstra(source, destination, false);
        cout << "Shortest distance from " << source << " to " << destination << ": " << shortestDistance << " minutes" << endl;
    } else {
        cout << "No path found from " << source << " to " << destination << endl;
    }

    return 0;
}
