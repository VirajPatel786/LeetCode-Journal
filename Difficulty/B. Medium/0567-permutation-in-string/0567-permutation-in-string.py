class Solution:
    def checkInclusion(self, pattern: str, text: str) -> bool:
        """
        Check if a permutation of the pattern is a substring of the text.

        Parameters:
        pattern (str): The pattern string for which we need to check permutations.
        text (str): The text string in which we check for permutations of the pattern.

        Returns:
        bool: True if a permutation of pattern exists as a substring in text, False otherwise.
        """
        pattern_length = len(pattern)
        text_length = len(text)

        # If the pattern is longer than the text, no permutation can be a substring
        if pattern_length > text_length:
            return False

        # Frequency counts of characters in pattern and the first window in text
        pattern_count = [0] * 26  # For storing frequency of each character in pattern
        window_count = [0] * 26   # For storing frequency of characters in current window of text

        # Fill the frequency count for the pattern and the first window of the text
        for i in range(pattern_length):
            pattern_count[ord(pattern[i]) - ord('a')] += 1
            window_count[ord(text[i]) - ord('a')] += 1

        # If the frequency of characters matches, the current window is a permutation
        if pattern_count == window_count:
            return True

        # Slide the window over the text, one character at a time
        for i in range(pattern_length, text_length):
            # Add the new character (right side of the window) to the window count
            window_count[ord(text[i]) - ord('a')] += 1
            
            # Remove the character that's left out of the window (left side of the window)
            window_count[ord(text[i - pattern_length]) - ord('a')] -= 1

            # Compare the pattern's character frequency with the current window's frequency
            if pattern_count == window_count:
                return True

        return False
