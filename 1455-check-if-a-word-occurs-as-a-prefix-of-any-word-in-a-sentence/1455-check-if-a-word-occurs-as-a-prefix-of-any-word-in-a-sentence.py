class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        """
        Check if searchWord is a prefix of any word in the sentence.

        Parameters:
        sentence (str): The input sentence containing words separated by spaces.
        searchWord (str): The word to check as a prefix.

        Returns:
        int: 1-based index of the first matching word or -1 if none.
        """
        words = sentence.split()  # Split sentence into words
        for index, word in enumerate(words, start=1):
            if word.startswith(searchWord):  # Check if searchWord is a prefix
                return index  # Return 1-based index of the matching word
        return -1  # Return -1 if no matching word is found
