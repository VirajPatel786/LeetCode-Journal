class Solution:
    def maximumSwap(self, num: int) -> int:
        """
        Returns the maximum number by swapping at most two digits of the given integer.

        Parameters:
        num (int): The input integer.

        Returns:
        int: The maximum number after at most one swap.
        """
        # Convert the number to a list of digits
        digits = list(str(num))
        
        # Create a dictionary to track the last position of each digit
        last = {int(d): i for i, d in enumerate(digits)}
        
        # Traverse the digits and find the first smaller digit that can be swapped with a larger one
        for i, d in enumerate(digits):
            # Check if there is a larger digit after the current one
            for bigger in range(9, int(d), -1):
                if last.get(bigger, -1) > i:
                    # Swap the digits
                    digits[i], digits[last[bigger]] = digits[last[bigger]], digits[i]
                    # Return the new number
                    return int("".join(digits))
        
        # If no swap has been made, return the original number
        return num
