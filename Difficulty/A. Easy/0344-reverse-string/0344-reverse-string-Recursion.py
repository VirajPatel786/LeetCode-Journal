class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        """
        Reverses the input list `s` in-place using recursion. This function does not return anything.
        
        Parameters:
        s (List[str]): A list of characters to be reversed in-place.
        
        Returns:
        None: The function modifies the input list in-place and does not return anything.
        """

        def helper(left: int, right: int) -> None:
            """
            Helper function to reverse the list using recursion.

            Parameters:
            left (int): The current index from the left side of the list.
            right (int): The current index from the right side of the list.

            Returns:
            None: The function swaps elements in place and calls itself recursively.
            """
            # Base case: if left index is greater than or equal to right index, stop recursion
            if left >= right:
                return

            # Swap the elements at the left and right indices
            s[left], s[right] = s[right], s[left]

            # Recursively call the helper function with updated pointers
            helper(left + 1, right - 1)

        # Initial call to the helper function with the full range of the list
        helper(0, len(s) - 1)