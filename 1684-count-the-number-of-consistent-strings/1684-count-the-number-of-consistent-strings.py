class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        """
        This function counts the number of consistent strings in the list 'words'.
        A string is consistent if all its characters are contained in the 'allowed' string.
        
        Parameters:
        allowed (str): A string containing allowed characters.
        words (List[str]): A list of words to be checked for consistency.
        
        Returns:
        int: The count of consistent strings.
        """
        
        # Convert the 'allowed' string into a set of characters for fast lookups
        allowedSet = set(allowed)
        
        # Initialize the count of consistent strings
        count = 0
        
        # Iterate through each word in the 'words' list
        for word in words:
            # Check if all characters in the current word are in allowedSet
            # The all() function returns True if every character is found in the allowedSet
            if all(char in allowedSet for char in word):
                # If the word is consistent, increment the count
                count += 1
        
        # Return the total count of consistent strings
        return count
