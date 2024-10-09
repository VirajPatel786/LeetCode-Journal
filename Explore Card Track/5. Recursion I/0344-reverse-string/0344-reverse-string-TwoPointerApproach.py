class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        """
        Reverses the input list `s` in-place. This function does not return anything.
        
        Parameters:
        s (List[str]): A list of characters to be reversed in-place.
        
        Returns:
        None: The function modifies the input list in-place and does not return anything.
        """
        # Initialize two pointers, one starting from the beginning (left)
        # and the other starting from the end (right) of the list
        left, right = 0, len(s) - 1

        # Swap elements at the left and right pointers until they meet in the middle
        while left < right:
            # Swap the elements at the two pointers
            s[left], s[right] = s[right], s[left]
            
            # Move the pointers towards the middle
            left += 1
            right -= 1