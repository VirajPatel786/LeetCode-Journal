class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        """
        This function counts how many words from the list 'words' are consistent with the 'allowed' string.
        A word is considered consistent if all characters in the word are present in the 'allowed' string.

        Parameters:
        allowed (str): A string containing allowed characters.
        words (List[str]): A list of words to check for consistency.

        Returns:
        int: The count of consistent strings.
        """

        # Create a boolean array to track allowed characters. There are 26 lowercase English letters.
        occur = [False] * 26
        count = 0  # Initialize the count of consistent strings

        # Mark each character in the 'allowed' string as present in the 'occur' array
        for c in allowed:
            occur[ord(c) - ord('a')] = True  # ord('a') to ord('z') are mapped to indices 0 to 25

        # Check each word in the 'words' list to see if it's consistent with the 'allowed' characters
        for word in words:
            # Use the check method to determine if the word is consistent
            if self.check(word, occur):
                count += 1  # Increment the count if the word is consistent

        return count  # Return the total count of consistent words

    def check(self, word: str, occur: List[bool]) -> bool:
        """
        This helper function checks if a word is consistent with the allowed characters.

        Parameters:
        word (str): The word to check.
        occur (List[bool]): A boolean list where True indicates that the character is allowed.

        Returns:
        bool: True if the word is consistent, False otherwise.
        """

        # For each character in the word, check if it's allowed by looking it up in the 'occur' array
        for c in word:
            if not occur[ord(c) - ord('a')]:  # If the character is not allowed, return False
                return False

        return True  # If all characters are allowed, return True