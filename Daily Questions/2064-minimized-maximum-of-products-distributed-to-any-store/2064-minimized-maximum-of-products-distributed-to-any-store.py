from typing import List

class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        """
        Find the minimized maximum number of products any store can receive.

        Parameters:
        n (int): Number of stores.
        quantities (List[int]): Array of quantities of each product type.

        Returns:
        int: The minimum possible maximum number of products given to any store.
        """

        # Helper function to check if we can distribute all products
        # such that no store receives more than 'max_products'
        def can_distribute(max_products: int) -> bool:
            stores_needed = 0  # Initialize the store count needed for this max limit
            for quantity in quantities:
                # Calculate the minimum number of stores needed for each product type
                # if no store can have more than 'max_products' products
                stores_needed += (quantity + max_products - 1) // max_products
                # If we exceed available stores, return False
                if stores_needed > n:
                    return False
            return True

        # Binary search for the minimized maximum number of products per store
        left, right = 1, max(quantities)  # Set bounds for binary search

        # Perform binary search
        while left < right:
            mid = (left + right) // 2  # Midpoint as the current max_products limit
            # Check if distribution is feasible with 'mid' as max products per store
            if can_distribute(mid):
                # If feasible, try to find a smaller maximum by adjusting 'right'
                right = mid
            else:
                # If not feasible, increase 'left' to search for larger values
                left = mid + 1

        return left  # The minimized maximum number of products any store receives
