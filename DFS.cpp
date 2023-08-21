#include <iostream>
#include <list>
using namespace std;
class Graph {
    int verticesCount; // Number of vertices in the graph
    list<int> *adjacencyLists; // Array of lists to store adjacency lists
    bool *visitedVertices; // Array to keep track of visited vertices
    public:
    Graph(int V); // Constructor to initialize the graph
    void addEdge(int src, int dest); // Method to add an edge to the graph
    void DepthFirstSearch(int vertex); // Method to perform Depth-First Search
};
// Constructor to initialize the graph
Graph::Graph(int vertices) {
    verticesCount = vertices;
    adjacencyLists = new list<int>[vertices];
    visitedVertices = new bool[vertices];
}
// Method to add edges to the graph
void Graph::addEdge(int src, int dest) {
    adjacencyLists[src].push_front(dest);
}
// Depth-First Search algorithm
void Graph::DepthFirstSearch(int vertex) {
    visitedVertices[vertex] = true; // Mark the current vertex as visited
    list<int>adjacentList=adjacencyLists[vertex];//Get the adjacency list of the current vertex
    cout << vertex << " "; // Print the current vertex
    list<int>::iterator iterator;
    for (iterator = adjacentList.begin(); iterator != adjacentList.end(); ++iterator) {
        if (!visitedVertices[*iterator]) { // If the adjacent vertex is not visited
            DepthFirstSearch(*iterator); // Recursively perform DFS on the adjacent vertex
        }
    }
}

int main() {
    Graph myGraph(9); // Create a graph with 9 vertices
    // Add edges to the graph
    myGraph.addEdge(7, 6); // Edge 1
    myGraph.addEdge(6, 5); // Edge 2
    myGraph.addEdge(2, 8); // Edge 3
    myGraph.addEdge(0, 1); // Edge 4
    myGraph.addEdge(2, 5); // Edge 5
    myGraph.addEdge(6, 8); // Edge 6
    myGraph.addEdge(2, 3); // Edge 7
    myGraph.addEdge(0, 7); // Edge 8
    myGraph.addEdge(1, 2); // Edge 9
    myGraph.addEdge(3, 4); // Edge 10
    myGraph.addEdge(4, 5); // Edge 11
    myGraph.addEdge(1, 7); // Edge 12
    myGraph.addEdge(3, 5); // Edge 13
    myGraph.DepthFirstSearch(2);//Perform DFS starting from vertex 2
    return 0;
}
