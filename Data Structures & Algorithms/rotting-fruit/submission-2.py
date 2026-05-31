from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        '''
            Same as pervious - multi source bfs -- keeping track of levels
        '''

        q = deque([])

        # collect rotten mango positions
        n = len(grid)
        m = len(grid[0])

        freshCount = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i,j))
                elif grid[i][j] == 1:
                    freshCount += 1

        moves = ((0,1),(1,0),(0,-1),(-1,0))
        visited = [[0 for _ in range(m)] for _ in range(n)]

        maxTime = 0
        time = 1

        while len(q) != 0:
            size = len(q)
            while size != 0:
                x,y = q.popleft()
                for (dx, dy) in moves:
                    nx = x+dx
                    ny = y+dy

                    if 0 <= nx < n and 0 <= ny < m and visited[nx][ny] == 0 and grid[nx][ny] != 0:
                        q.append((nx,ny))
                        visited[nx][ny] = 1

                        if grid[nx][ny] == 1:
                            freshCount -= 1
                            maxTime = max(maxTime, time)

                size -= 1

            time += 1

        return maxTime if freshCount == 0 else -1

