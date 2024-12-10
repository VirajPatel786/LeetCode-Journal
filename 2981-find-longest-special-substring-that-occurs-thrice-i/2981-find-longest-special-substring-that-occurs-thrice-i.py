from collections import Counter

class Solution:
    def maximumLength(self, s: str) -> int:
        """
        Finds the length of the longest special substring that occurs at least thrice.

        A special substring consists of only one repeated character (e.g., "aaa", "b").
        The function generates all possible special substrings and identifies the longest
        one that appears at least three times in the input string.

        Parameters:
        s (str): The input string consisting of lowercase English letters.

        Returns:
        int: The length of the longest special substring that occurs at least thrice, or -1 if none exist.
        """
        # Generate all special substrings and count their frequencies
        counter = Counter()
        n = len(s)
        i = 0
        
        while i < n:
            j = i
            # Find the length of the contiguous segment of the same character
            while j < n and s[j] == s[i]:
                j += 1
            length = j - i
            
            # Add all substrings from this segment to the counter
            for k in range(1, length + 1):
                for start in range(i, j - k + 1):
                    counter[s[start:start + k]] += 1
            
            i = j

        # Find the maximum length of substrings that appear at least three times
        max_length = -1
        for substr, count in counter.items():
            if count >= 3:
                max_length = max(max_length, len(substr))

        return max_length