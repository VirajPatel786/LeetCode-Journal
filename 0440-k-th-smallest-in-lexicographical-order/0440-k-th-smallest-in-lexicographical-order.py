class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        """
        Finds the k-th lexicographically smallest integer in the range [1, n].

        Parameters:
        n (int): The upper limit of the range.
        k (int): The position (1-indexed) of the lexicographically smallest number to find.

        Returns:
        int: The k-th lexicographically smallest number.
        """
        current_number = 1  # Start with the smallest lexicographical number (1).

        # Continue until we find the k-th smallest number.
        while k > 1:
            count = 0  # Count of numbers in the subtree rooted at `current_number`.

            # Calculate how many numbers exist under the prefix `current_number`.
            step_size = 1
            prefix = current_number
            while prefix <= n:
                # Count numbers in the range [prefix, min(prefix + step_size - 1, n)].
                count += min(n + 1, prefix + step_size) - prefix
                prefix *= 10
                step_size *= 10

            # If the subtree rooted at `current_number` contains fewer than `k` numbers, skip it.
            if k > count:
                k -= count  # Skip the current subtree.
                current_number += 1  # Move to the next lexicographical prefix.
            else:
                k -= 1  # Go deeper into the current subtree.
                current_number *= 10  # Move to the next level in the tree (prefix becomes `current_number0`).

        return current_number  # Return the k-th smallest number.