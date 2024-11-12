from typing import List
from bisect import bisect_right


class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        """
        Computes the maximum beauty for each query based on item prices and their beauties.

        Parameters:
        items (List[List[int]]): A list where each sublist contains [price, beauty] for each item.
        queries (List[int]): A list of maximum prices for which to find the maximum beauty.

        Returns:
        List[int]: A list containing the maximum beauty for each query.
        """

        # Step 1: Sort items by price, then by beauty in descending order for same price
        items.sort()

        # Step 2: Compute prefix max array for beauty up to each price point
        max_beauty = 0
        prefix_max = []
        prices = []

        for price, beauty in items:
            max_beauty = max(max_beauty, beauty)
            prefix_max.append(max_beauty)
            prices.append(price)

        # Step 3: Process each query using binary search
        result = []
        for query in queries:
            # Find the index of the largest price <= query using binary search
            idx = bisect_right(prices, query) - 1

            if idx >= 0:
                result.append(prefix_max[idx])  # Beauty for the highest price <= query
            else:
                result.append(0)  # No items affordable, beauty is 0

        return result
