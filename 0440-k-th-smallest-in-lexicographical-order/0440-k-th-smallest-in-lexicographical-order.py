class Solution:
    def count_steps(self, prefix: int, n: int) -> int:
        """
        Counts how many numbers exist with the given prefix in the range [1, n].
        
        Parameters:
        prefix (int): The current prefix (root of a subtree in lexicographical order).
        n (int): The upper limit of the range.
        
        Returns:
        int: The number of lexicographical steps (i.e., valid numbers) between `prefix`
             and `next_prefix` that are within the range [1, n].
        """
        current = prefix
        next_prefix = prefix + 1  # The next prefix in lexicographical order (e.g., after `1` is `2`)
        steps = 0

        # Traverse down the tree by powers of 10, counting how many numbers lie between
        # `prefix` and `next_prefix` at each level of the tree.
        while current <= n:
            # Add the range of numbers from `current` to `min(n + 1, next_prefix)` in the current level.
            steps += min(n + 1, next_prefix) - current
            current *= 10       # Move to the next level in the tree (by appending digits to the prefix)
            next_prefix *= 10   # Update the next_prefix accordingly.
        return steps

    def findKthNumber(self, n: int, k: int) -> int:
        """
        Finds the k-th lexicographically smallest integer in the range [1, n].
        
        Parameters:
        n (int): The upper limit of the range.
        k (int): The position (1-indexed) of the lexicographically smallest number to find.

        Returns:
        int: The k-th lexicographically smallest number.
        """
        # Start from the smallest number, which is `1`.
        current = 1
        # Decrease `k` by 1, because we are starting from the first number (i.e., `1`).
        k -= 1

        # Loop until we find the k-th smallest number.
        while k > 0:
            # Count how many numbers exist in the subtree rooted at `current`.
            steps = self.count_steps(current, n)
            
            if steps <= k:
                # If the entire subtree rooted at `current` has fewer or equal numbers than `k`,
                # we skip this subtree by moving to the next prefix.
                current += 1
                k -= steps
            else:
                # If the subtree contains more than `k` numbers, we go deeper into the subtree,
                # by multiplying `current` by 10 to move to the next level.
                current *= 10
                k -= 1

        return current
