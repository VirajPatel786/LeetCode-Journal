class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        """
        Determines if `goal` is a rotation of `s`.

        Parameters:
        s (str): The original string.
        goal (str): The target string to check for rotation.

        Returns:
        bool: True if `goal` is a rotation of `s`, False otherwise.
        """
        
        # Check if lengths are different; if so, rotation is impossible
        if len(s) != len(goal):
            return False
        
        # Check if goal is a substring of s + s, which would indicate rotation
        return goal in (s + s)
