class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        
        res = []

        for i in range(n):
            if i != 0 and nums[i] == nums[i-1]:
                continue

            p1 = i+1
            p2 = n-1
            while p1 < p2:
                #print(nums[p1], nums[p2])
                if nums[p1] + nums[p2] + nums[i] == 0:
                    res.append([nums[i],nums[p1],nums[p2]])
                    p1 += 1
                    p2 -= 1
                    while p1 < n and (p1 == 0 or nums[p1] == nums[p1-1]):
                        p1 += 1
                    while p2 >= 0 and (p2 == n-1 or nums[p2] == nums[p2+1]):
                        p2 -= 1
                elif nums[p1] + nums[p2] < (-1*nums[i]):
                    p1 += 1
                else:
                    p2 -= 1
                
        return res