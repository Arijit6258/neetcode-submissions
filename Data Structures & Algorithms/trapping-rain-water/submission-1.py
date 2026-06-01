class Solution:
    def trap(self, height: List[int]) -> int:
        # for each index -- min(leftHeighest, rightHeighest) * height of current index

        n = len(height)
        leftMax = 0
        lMax = [-1]

        total = 0

        for i in range(1, n):
            leftMax = max(leftMax, height[i-1])
            lMax.append(leftMax)

        rightMax = -1
        for j in range(n-2, -1, -1):
            rightMax = max(rightMax, height[j+1])

            if lMax[j] > height[j] and height[j] < rightMax:
                total += min(lMax[j], rightMax) - height[j]

        return total

        