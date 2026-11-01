#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <utility>

using namespace std;

class Graph
{
    private:
        int num_vertices;
        vector<vector<int>> adj_list;
    
    public:
        Graph(int num): num_vertices(num), adj_list(num + 1) {}

    void add_edge(pair<int, int> vertices)
    {
        int from = vertices.first;
        int to = vertices.second;

        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }

    void add_edges(vector<pair<int, int>> edges)
    {
        for (const auto& e : edges)
        {
            add_edge(e);
        }
    }

    vector<int> dfs_traversal(int start_vertex)
    {
        vector<int> traversal_seq;
        unordered_set<int> visited;
        stack<int> to_visit;
        to_visit.push(start_vertex);

        while(!to_visit.empty())
        {
            int current_vertex = to_visit.top();
            to_visit.pop();

            if(!visited.count(current_vertex))
            {
                traversal_seq.push_back(current_vertex);
                visited.insert(current_vertex);

                for (auto rest : adj_list[current_vertex])
                {
                    if(!visited.count(rest))
                    {
                        to_visit.push(rest);
                    }
                }
            }
        }
        return traversal_seq;

    }
};


int main()
{
    Graph graph(9);

    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 5},
        {1, 4},
        {2, 5},
        {2, 3},
        {3, 6},
        {4, 7},
        {7, 8},
        {8, 9}

    };

    graph.add_edges(edges);

    vector<int> traverse = graph.dfs_traversal(1);
    cout << "Final traversal sequence:\n";
    for (const auto& v : traverse)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}