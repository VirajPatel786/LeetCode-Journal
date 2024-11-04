from typing import List
from functools import lru_cache

class Solution:
    """
    Calculates the minimum total distance traveled by robots to reach factories.
    """
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        """
        Determines the minimum total distance all robots need to travel to be repaired,
        given each factory's repair limits and robot/factory positions.

        Parameters:
        robot (List[int]): List of robot positions along the X-axis.
        factory (List[List[int]]): List of factories, where each factory is represented
                                   by [position, limit].

        Returns:
        int: Minimum total distance all robots need to travel for repairs.
        """
        # Sort robots and factories for efficient assignment
        robot.sort()
        factory.sort()

        n, m = len(robot), len(factory)

        @lru_cache(None)
        def dp(i: int, j: int) -> int:
            """
            Recursively calculates the minimum distance to assign robots to factories,
            utilizing memoization for efficiency.

            Parameters:
            i (int): Current index of the robot being assigned.
            j (int): Current index of the factory being considered.

            Returns:
            int: Minimum total travel distance for robots to be repaired up to index `i`.
            """
            if i == n:  # All robots assigned
                return 0
            if j == m:  # Out of factories to assign to
                return float('inf')

            # Option 1: Skip this factory
            res = dp(i, j + 1)

            # Option 2: Assign robots to the current factory within its limit
            total_distance = 0
            for k in range(min(factory[j][1], n - i)):
                total_distance += abs(robot[i + k] - factory[j][0])
                res = min(res, total_distance + dp(i + k + 1, j + 1))

            return res

        return dp(0, 0)
