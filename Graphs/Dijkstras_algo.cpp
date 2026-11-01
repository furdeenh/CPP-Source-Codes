#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

#define INF INT_MAX

using namespace std;

class Graph {
private:
    int num_vertices;
    vector<vector<pair<int, int>>> adj_list;

public:
    Graph(int num) : num_vertices(num), adj_list(num + 1) {}

    void add_edge(pair<int, int> vertices, bool is_directed = false, int weight = 0)
    {
        int from = vertices.first;
        int to = vertices.second;

        adj_list[from].push_back({to, weight});
        if(!is_directed)
        {
            adj_list[to].push_back({from, weight});
        }
    }

    int dijkstra(int src, int dest, vector<int>& path)
    {
        vector<int> distance(num_vertices + 1, INF);
        distance[src] = 0;
        vector<int> predecessor(num_vertices + 1);
        predecessor[src] = src;
        vector<bool> processed(num_vertices + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, src});

        while(!pq.empty())
        {
            int current_vertex = pq.top().second;
            pq.pop();
            if(processed[current_vertex])
            {
                continue;
            }
            processed[current_vertex] = true;
            for (auto n : adj_list[current_vertex])
            {
                int v = n.first;
                int dis = n.second;

                if (distance[current_vertex] + dis < distance[v] )
                {
                    distance[v] = distance[current_vertex] + dis;
                    pq.push({distance[v], v});
                    predecessor[v] = current_vertex;

                }
            }
        }
        int current = dest;
        while (true)
        {
            path.push_back(current);
            if (predecessor[current] == current)
            {
                break;
            }
            current = predecessor[current];
        }
        reverse(path.begin(), path.end());
        return distance[dest];
    }


};

int main() {
    Graph graph(6);

    graph.add_edge({1, 2}, false, 4);
    graph.add_edge({1, 3}, false, 4);
    graph.add_edge({2, 3}, false, 2);
    graph.add_edge({3, 4}, false, 3);
    graph.add_edge({3, 5}, false, 1);
    graph.add_edge({3, 6}, false, 6);
    graph.add_edge({4, 6}, false, 2);
    graph.add_edge({5, 6}, false, 3);

    int src = 1;
    int dest = 6;
    vector<int> path;
    int distance = graph.dijkstra(src, dest, path);

    cout << distance << "\n";
    for(auto item: path) {
        cout << item << " ";
    }

    return 0;
}