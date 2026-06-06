from collections import deque

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        '''
        A car can create fleet with a car to its right
        I want to process the cars from right to left

        If for current car there's a car to its right which can make fleet together
        for each car we can find out time required to reach target

        let's consider two positions with time required

        p1 -> t1
        p2 -> t2

        if t1 >= t2 then it is a fleet.

        if there are multiple tis to the right of t1 i.e. t1 >= ti1 >= ti2

        we can pick the first right car.

        i -> t1
        j -> t2
        k -> t3

        i can not move over j to catch k if i catches both j and k cause
        either i will catch j and them move with j's speed or j will catch k 
        before i and j&k will move with k's speed.

        we want the last tj for ti i.e. ti >= tj

        while processing from right to left we always want the time taken to reach destination
        to be decreasing so that we encounter the last car which takes lesser time than current.

        I have to use monotonically increasing stack.
        '''
        timeTaken = deque([])

        n = len(speed)

        cars = [(position[i], speed[i]) for i in range(n)]
        sortedCars = sorted(cars, key=lambda x: x[0])
        fleet = n
        # starting with max fleet, will reducing as we merge the cars

        for i in range(n-1, -1, -1):
            time = (target-sortedCars[i][0]) / sortedCars[i][1]
            while timeTaken and timeTaken[0] < time:
                timeTaken.popleft()

            if timeTaken: # if empty then all are smaller and no car to fleet with
                fleet -= 1

            print(fleet)

            timeTaken.appendleft(time)

        return fleet



