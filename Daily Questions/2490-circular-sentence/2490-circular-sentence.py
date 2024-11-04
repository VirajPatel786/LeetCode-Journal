class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        """
        Determines if a sentence is circular.

        Parameters:
        sentence (str): The sentence to be checked.

        Returns:
        bool: True if the sentence is circular, False otherwise.
        """
        
        # Split sentence into individual words
        words = sentence.split()

        # Iterate through each word in the sentence
        for i in range(len(words)):
            # Determine the last character of the current word
            last_char = words[i][-1]
            
            # For the last word, compare its last character to the first character of the first word
            if i == len(words) - 1:
                first_char_next = words[0][0]
            else:
                # For other words, compare the last character of the current word 
                # with the first character of the next word
                first_char_next = words[i + 1][0]

            # Check if the characters match; if not, return False
            if last_char != first_char_next:
                return False
        
        # If all checks passed, return True
        return True
