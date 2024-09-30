from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        """
        Determines which kids can have the greatest number of candies if given extraCandies.

        Parameters:
        candies (List[int]): A list where each element represents the number of candies a kid has.
        extraCandies (int): The number of extra candies that can be given to any one kid.

        Returns:
        List[bool]: A list of booleans indicating whether each kid can have the greatest or 
        equal number of candies if given the extraCandies.
        """
        # Find the maximum number of candies any kid currently has
        max_candies = max(candies)
        
        # List comprehension to build the result in a single pass
        return [(candie + extraCandies >= max_candies) for candie in candies]
