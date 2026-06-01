class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        # 1 2 5 5
        # pair the max with the min -- if we can pair max and min of current then that will be optimal
        
        i = 0
        j = len(people)-1

        people.sort()

        num = 0

        while i <= j:
            if i == j or people[i]+people[j] <= limit:
                num += 1
                i += 1
                j -= 1
            else:
                num += 1
                j -= 1

        return num
        