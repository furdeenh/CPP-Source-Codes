class Solution {
public:
    
    void bfs_traversal(vector<vector<char>>& grid, vector<vector<bool>>& visited, int start_row, int start_col) // (g, !, 0, 0);
    {
        int rows = grid.size();       //  4
        int cols = grid[0].size();   // 5

        queue<pair<int, int>> q;
        q.push({start_row, start_col});  // {0, 0}
        visited[start_row][start_col] = true;

        vector<pair<int, int>> directions =
        {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        while (!q.empty())
        {
            pair<int, int> current = q.front();   // {0,0}
            q.pop();
            
            for (const auto& d : directions)
            {
                int next_row = current.first + d.first;
                int next_col = current.second + d.second;

                if (next_row < 0 || next_row >= rows || next_col < 0 || next_col >= cols)
                {
                    continue;
                }

                if (grid[next_row][next_col] == '1' && !visited[next_row][next_col])
                {
                    visited[next_row][next_col] = true;
                    q.push({next_row, next_col});
                }
            }
        }
    }
    

    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int islands = 0;
        
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == '1' && !visited[r][c])
                {
                    ++islands;
                    bfs_traversal(grid, visited, r, c);
                }
            }
        }
        return islands;
    }
};