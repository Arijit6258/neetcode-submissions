from collections import deque

class Solution:
    def traverse(self, heights, reachable, i, j, n, m):
        if reachable[i][j] == 1:
            return

        moves = ((0,1),(0,-1),(1,0),(-1,0))

        q = deque([(i,j)])
        reachable[i][j] = 1

        while len(q) != 0:
            (x,y) = q.popleft()

            for (moveX, moveY) in moves:
                nextX = x+moveX
                nextY = y+moveY

                if (0 <= nextX < n and 0 <= nextY < m and reachable[nextX][nextY] == 0 and heights[nextX][nextY] >= heights[x][y]):
                    reachable[nextX][nextY] = 1
                    q.append((nextX,nextY))



    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n = len(heights)
        m = len(heights[0])

        Preachable = [[0 for _ in range(m)] for _ in range(n)]
        Areachable = [[0 for _ in range(m)] for _ in range(n)]

        for j in range(m):
            self.traverse(heights, Preachable, 0, j, n, m)
            self.traverse(heights, Areachable, n-1, j, n, m)

        for i in range(n):
            self.traverse(heights, Preachable, i, 0, n, m)
            self.traverse(heights, Areachable, i, m-1, n, m)
                

        result = []

        for i in range(n):
            for j in range(m):
                if Areachable[i][j] == 1 and Preachable[i][j] == 1:
                    result.append([i,j])

        return result


        
