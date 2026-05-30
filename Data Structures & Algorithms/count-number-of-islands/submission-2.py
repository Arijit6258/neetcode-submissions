from collections import deque

class Solution:
    moves = [[0,1],[1,0],[0,-1],[-1,0]]

    def markIsland(self, grid, visited, i, j, n, m):
        # BFS - Dijkstra
        q = deque([(i,j)])
        ind = 0

        while len(q) != 0:
            nxt0, nxt1 = q.popleft()
            ind += 1
            visited[nxt0][nxt1] = 1

            for move in self.moves:
                nextI = nxt0+move[0]
                nextJ = nxt1+move[1]

                if 0 <= nextI < n and 0 <= nextJ < m and grid[nextI][nextJ] == '1' and visited[nextI][nextJ] == 0:
                    visited[nextI][nextJ] = 1
                    q.append([nextI,nextJ])

    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid);
        m = len(grid[0]);
        island = 0
        visited = [[0 for _ in range(m)] for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1' and visited[i][j] == 0:
                    island += 1
                    self.markIsland(grid, visited, i, j, n, m)

        return island