class Solution:
    def arrayRankTransform(self, arr: list[int]) -> list[int]:
        """
        Rank transformation of an array.

        Parameters:
        arr (List[int]): List of integers to transform into ranks.

        Returns:
        List[int]: List of integers where each element is replaced with its rank.
        """
        if not arr:
            return []

        # Step 1: Sort unique elements
        sorted_unique = sorted(set(arr))

        # Step 2: Create a rank map
        rank_map = {num: rank + 1 for rank, num in enumerate(sorted_unique)}

        # Step 3: Transform the original array using the rank map
        return [rank_map[num] for num in arr]