#include <iostream>

using namespace std;

const int INF = 1e9;

int minDistance(int dist[], bool visited[], int V) {
    int minDist = INF, minIndex = -1;
    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}      

void printMST(int parent[], int graph[][100], int V) {
    cout << "Edge   Weight" << endl;
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "   " << graph[i][parent[i]] << endl;
}


void dijkstraMST(int graph[][100], int V) {
    int parent[V], dist[V];
    bool visited[V] = {false};

    for (int i = 0; i < V; ++i) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[0] = 0;

   for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;
       
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[100][100]; // Assuming a maximum of 100 vertices

    cout << "Enter the adjacency matrix representing the graph:\n";
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];

    dijkstraMST(graph, V);

    return 0;
}
