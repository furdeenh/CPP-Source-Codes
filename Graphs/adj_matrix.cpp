// Non Directed

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    private:
        int num_vertices;
        vector<vector<int>> adj_matrix;

    public:
        Graph(int num): num_vertices(num), adj_matrix(num + 1, vector<int>(num + 1, 0)) {}

    void add_edge(int from, int to, bool is_directed = false, int weight = 1)
    {
        adj_matrix[from][to] = weight;
        if (!is_directed)
        {
            adj_matrix[to][from] = weight; 
        }    
    }

    void print_adj_matrix()
    {
        for (int i = 1; i <= num_vertices; ++i)
        {
            for (int j = 1; j <= num_vertices; ++j)
            {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    // Write your code here
    Graph graph(5);

    graph.add_edge(3, 1, false, 5);
    graph.add_edge(2, 1, true, 4);
    graph.add_edge(5, 3, true, 7);
    graph.add_edge(1, 5, true, 2);
    graph.add_edge(5, 4, true, 2);
    graph.add_edge(2, 4, true, 4);
    

    graph.print_adj_matrix();

    return 0;
}