class Solution:
    def canChange(self, start: str, target: str) -> bool:
        """
        Determines if the string target can be obtained from start.

        Parameters:
        start (str): The starting configuration.
        target (str): The target configuration.

        Returns:
        bool: True if target can be obtained, False otherwise.
        """
        n = len(start)
        i, j = 0, 0  # Pointers for start and target

        while i < n or j < n:
            # Skip underscores in start
            while i < n and start[i] == '_':
                i += 1
            # Skip underscores in target
            while j < n and target[j] == '_':
                j += 1

            # Both strings should end together
            if i == n and j == n:
                return True

            # If one string ends before the other
            if i == n or j == n:
                return False

            # Mismatch of characters
            if start[i] != target[j]:
                return False

            # Validate movement constraints
            if start[i] == 'L' and i < j:
                return False  # 'L' cannot move to the right
            if start[i] == 'R' and i > j:
                return False  # 'R' cannot move to the left

            # Move both pointers
            i += 1
            j += 1

        return True
