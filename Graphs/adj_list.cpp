#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Graph
{
    private:
        int num_vertices;
        vector<vector<pair<int, int>>> adj_list;

    public:
    
    Graph(int num): num_vertices(num), adj_list(num_vertices + 1) {}

    void add_edge(pair<int, int> vertices, bool is_directed = false, int weight = 1)
    {
        int from = vertices.first;
        int to = vertices.second;

        adj_list[from].push_back({to, weight});
        if (!is_directed)
        {
            adj_list[to].push_back({from, weight});
        }
    }

    void print_adj_list()
    {
        for (int i = 1; i <= num_vertices; ++i)
        {
            cout << i << " -> ";
            for (const auto& vertex : adj_list[i])
            {
                if (vertex.second != 0)
                {
                    cout << "(" << vertex.first << ", " << vertex.second << ") "; 
                } else {
                    cout << vertex.first << " ";
                }
            }
            cout << endl;
        }
    }

};

int main() {
    Graph graph(5);

    // Write your code here
    graph.add_edge({2, 4}, true, 4);
    graph.add_edge({1, 5}, true, 2);
    graph.add_edge({3, 1}, true, 5);
    graph.add_edge({5, 4}, true, 2);
    graph.add_edge({2, 1}, true, 4);
    graph.add_edge({5, 3}, true, 7);

    graph.print_adj_list();

    return 0;
}