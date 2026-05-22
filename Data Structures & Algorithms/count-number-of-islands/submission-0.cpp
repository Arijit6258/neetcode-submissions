class Solution {
public:
    vector<vector<int>> changes = {{1,0}, {0,1}, {0,-1},{-1,0}};

    void visitIsland(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (visited[i][j]) return;
        
        visited[i][j] = true;
        
        for (vector<int> ch : changes) {
            int ni = i+ch[0], nj = j+ch[1];
            if (ni < grid.size() && nj < grid[0].size() && grid[ni][nj] == '1') {
                visitIsland(grid, visited, ni, nj);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    visitIsland(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};
