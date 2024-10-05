from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        """
        Check if a permutation of s1 is a substring of s2.

        Parameters:
        s1 (str): First input string.
        s2 (str): Second input string.

        Returns:
        bool: True if a permutation of s1 is a substring of s2, otherwise False.
        """

        len_s1, len_s2 = len(s1), len(s2)
        if len_s1 > len_s2:
            return False
        
        s1_count = Counter(s1)
        window_count = Counter()

        for i in range(len_s2):
            # Add one char to the window
            window_count[s2[i]] += 1
            
            # Remove one char from the window if it's larger than s1
            if i >= len_s1:
                if window_count[s2[i - len_s1]] == 1:
                    del window_count[s2[i - len_s1]]
                else:
                    window_count[s2[i - len_s1]] -= 1

            # Compare the window's character count with s1's character count
            if window_count == s1_count:
                return True

        return False