#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet, int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(const std::vector<int>& parent, int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    std::cout << j << " ";
}

void Dijkstra(const std::vector<std::vector<int>>& graph, int src, int V, int target) {
    std::vector<int> dist(V, INF);
    std::vector<bool> sptSet(V, false);
    std::vector<int> parent(V, -1);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    std::cout << "The shortest path from " << src << " to " << target << " is: ";
    printPath(parent, target);
    std::cout << "\nThe path cost is: " << dist[target] << std::endl;
}

int main() {
    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;

    std::vector<std::vector<int>> graph(V, std::vector<int>(V));
    std::cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            std::cin >> graph[i][j];

    int source, target;
    std::cout << "Enter the source node: ";
    std::cin >> source;
    std::cout << "Enter the target node: ";
    std::cin >> target;

    Dijkstra(graph, source, V, target);

    return 0;
}
Output:
/tmp/QWskDgVjR4.o
Enter the number of vertices: 5
Enter the adjacency matrix:
0 10 0 0 5
10 0 3 0 0
0 3 0 4 0
0 0 4 0 2
5 0 0 2 0

0 10 0 0 5

10 0 3 0 0

0 3 0 4 0

0 0 4 0 2

5 0 0 2 0


Enter the source node: 0
Enter the target node: 4
The shortest path from 0 to 4 is: 4 
The path cost is: 5
