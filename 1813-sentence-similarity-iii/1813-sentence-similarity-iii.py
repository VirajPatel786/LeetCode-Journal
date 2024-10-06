class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        """
        This function checks whether sentence1 and sentence2 can be made similar
        by inserting a substring into one of the sentences.

        Parameters:
        sentence1 (str): First input sentence.
        sentence2 (str): Second input sentence.

        Returns:
        bool: Returns True if the sentences can be made similar, False otherwise.
        """
        
        # Split the sentences into lists of words
        s1 = sentence1.split()  # List of words in sentence1
        s2 = sentence2.split()  # List of words in sentence2
        
        # Initialize two pointers for prefix and suffix matching
        i, j = 0, 0
        
        # Check prefix matches: Compare words from the start of both lists
        # Increment i as long as the words at index i are the same in both lists
        while i < len(s1) and i < len(s2) and s1[i] == s2[i]:
            i += 1
        
        # Check suffix matches: Compare words from the end of both lists
        # Increment j as long as the words at index -1-j are the same in both lists
        while j < len(s1) - i and j < len(s2) - i and s1[-1-j] == s2[-1-j]:
            j += 1
        
        # If the remaining unmatched part between prefix and suffix is valid, return True
        # Matched prefix + suffix must cover at least one of the sentences entirely
        return i + j >= len(s2) or i + j >= len(s1)
