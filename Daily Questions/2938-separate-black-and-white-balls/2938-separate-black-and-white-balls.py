class Solution:
    def minimumSteps(self, s: str) -> int:
        """
        Calculate the minimum number of steps to group all black balls to the right
        and all white balls to the left.

        Parameters:
        s (str): A binary string representing the sequence of black (1) and white (0) balls.

        Returns:
        int: The minimum number of swaps required.
        """
        white_count = 0  # Initialize the total number of swaps required
        min_steps = 0     # Track the number of black balls encountered so far
        
        for char in s:
            if char == '0':
                # For each white ball, add the number of black balls encountered so far
                # This simulates moving the black balls past the white balls
                white_count += min_steps
            else:
                # For each black ball, increment the number of black balls encountered
                min_steps += 1

        return white_count  # Return the total number of swaps required
