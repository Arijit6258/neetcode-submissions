from collections import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        '''
        brute force, for each land cell do bfs - dijkstra's algorithm.

        optimized : 

            do multi sourced bfs. start from treasure chests and keep doing level wise bfs until finished.

        '''
        
        INF = 2147483647

        q = deque([])

        n = len(grid)
        m = len(grid[0])

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    q.append((i,j))

        diffs = ((0,1),(1,0),(0,-1),(-1,0))
        visited = [[False for _ in range(m)] for _ in range(n)]

        while len(q) != 0:
            x, y = q.popleft()
            visited[x][y] = 1

            for dx, dy in diffs:
                nx = x+dx
                ny = y+dy

                if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == INF and not visited[nx][ny]:
                    visited[nx][ny] = 1
                    grid[nx][ny] = grid[x][y]+1
                    q.append((nx,ny))


        