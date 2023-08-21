#include <iostream>
#include <list>
using namespace std;
class Graph {
    int numVertices;
    list<int>* adjacencyLists;
    bool* isVisited;

    public:
    Graph(int vertices);
    void addEdge(int source, int destination);
    void breadthFirstSearch(int startVertex);
};
// Constructor to create a graph with given vertices
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjacencyLists = new list<int>[vertices];
}
// Function to add edges to the graph
void Graph::addEdge(int source, int destination) {
    adjacencyLists[source].push_back(destination);
    adjacencyLists[destination].push_back(source); // Assuming an undirected graph
}
// Breadth-First Search algorithm
void Graph::breadthFirstSearch(int startVertex) {
    isVisited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        isVisited[i] = false;
    list<int> queue;
    isVisited[startVertex] = true;
    queue.push_back(startVertex);
    list<int>::iterator it;
    while (!queue.empty()) {
        int currentVertex = queue.front();
        cout << "=> " << currentVertex << " ";
        queue.pop_front();
for (it=adjacencyLists[currentVertex].begin();it!=adjacencyLists[currentVertex].end();++it){
            int adjacentVertex = *it;
            if (!isVisited[adjacentVertex]) {
                isVisited[adjacentVertex] = true;
                queue.push_back(adjacentVertex);
            }
        }
    }
}
int main() {
    Graph graph(9);
    graph.addEdge(0, 1);
    graph.addEdge(0, 7);
    graph.addEdge(1, 2);
    graph.addEdge(1, 7);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);
    graph.addEdge(2, 8);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);
    graph.addEdge(6, 8);
    graph.addEdge(7, 8);
    graph.breadthFirstSearch(4);
    return 0;
}
