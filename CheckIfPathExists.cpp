/*There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. No vertex has an edge to itself and there can be multiple edges between two vertices.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, Print "Yes" if there is a valid path from source to destination, or "No" otherwise.*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfs(int node, int destination, vector<vector<int>>& graph, unordered_set<int>& visited) {
    if (node == destination) {
        return true;
    }

    visited.insert(node);

    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            if (dfs(neighbor, destination, graph, visited)) {
                return true;
            }
        }
    }

    return false;
}

string has_valid_path(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> graph(n);

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    unordered_set<int> visited;

    return dfs(source, destination, graph, visited) ? "Yes" : "No";
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2));

    for (int i = 0; i < n; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int source, destination;
    cin >> source >> destination;

    cout << has_valid_path(n, edges, source, destination) << endl;

    return 0;
}
