from collections import deque

class Solution:
    moves = ((0,1),(1,0),(0,-1),(-1,0))

    def getArea(self, grid, visited, i, j, n, m):
        q = deque([(i,j)])

        area = 1

        while len(q) != 0:
            x, y = q.popleft()
            visited[x][y] = True

            for dx, dy in self.moves:
                nx = x+dx
                ny = y+dy

                if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 1 and visited[nx][ny] == False:
                    q.append((nx,ny))
                    area += 1
                    visited[nx][ny] = True

        return area



    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        visited = [[False for _ in range(m)] for _ in range(n)]

        maxArea = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and visited[i][j] == False:
                    print(1)
                    maxArea = max(maxArea, self.getArea(grid, visited, i, j, n, m))

        return maxArea