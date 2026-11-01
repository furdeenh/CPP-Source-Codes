// Replace ___ with your code

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;

class Graph {
private:
    int num_vertices;
    vector<vector<int>> adj_list;

public:

    // Constructor
    Graph(int num_vertices) : num_vertices(num_vertices), adj_list(num_vertices + 1) {}

    // Method to add an edge
    void add_edge(pair<int, int> vertices) {
        int from_vertex = vertices.first;
        int to_vertex = vertices.second;

        // Add the edge
        adj_list[from_vertex].push_back(to_vertex);
        adj_list[to_vertex].push_back(from_vertex);
    }

    void add_edges(vector<pair<int, int>> edges) {
        for(const auto& edge: edges) {
            add_edge(edge);
        }
    }

    // Perform BFS traversal
    vector<int> bfs_traversal(int start_index)
    {
        vector<int> traversal_seq;
        unordered_set<int> visited;
        queue<int> q;
        q.push(start_index);

        while(!q.empty())
        {
            int current_vertex = q.front();
            q.pop();
            if(!visited.count(current_vertex))
            {
                traversal_seq.push_back(current_vertex);
                visited.insert(current_vertex);

                for (auto rest : adj_list[current_vertex])
                {
                    if(!visited.count(rest))
                    {
                        q.push(rest);
                    }
                }
            }
        }
        return traversal_seq;

    }



};

int main() {
    Graph graph(9);

    // Create edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {2, 5},
        {3, 6},
        {5, 6}
    };

    graph.add_edges(edges);

    // Perform BFS traversal
    vector<int> traverse = graph.bfs_traversal(1);
    for (const auto& v : traverse) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}