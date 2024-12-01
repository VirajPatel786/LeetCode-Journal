class Solution:
    def checkIfExist(self, arr):
        """
        Check if there exist indices i and j such that arr[i] == 2 * arr[j].

        Parameters:
        arr (List[int]): List of integers.

        Returns:
        bool: True if such a pair exists, otherwise False.
        """
        seen = set()  # Set to store numbers seen so far
        for num in arr:
            # Check if the double of the current number or half (if even) exists in the set
            if 2 * num in seen or (num % 2 == 0 and num // 2 in seen):
                return True
            # Add the current number to the set for future checks
            seen.add(num)
        return False  # Return False if no such pair exists
