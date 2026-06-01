class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # find first greater closest int from x in array

        # binary search
        i = 0
        n = len(arr)
        j = n-1

        arr.sort()

        while i < j:
            mid = (i+j)//2
            if arr[mid] > x:
                j = mid
            else:
                i = mid+1


        res = []
        if i == 0:
            return arr[0:k]
        else:
            p1 = i-1
            p2 = i

            while k != 0:
                if p1 == -1:
                    res.append(arr[p2])
                    p2 += 1
                elif p2 == n:
                    res.append(arr[p1])
                    p1 -= 1
                elif x-arr[p1] > arr[p2]-x:
                    res.append(arr[p2])
                    p2 += 1
                else:
                    res.append(arr[p1])
                    p1 -= 1

                k -= 1

            res.sort()
            return res

            
        