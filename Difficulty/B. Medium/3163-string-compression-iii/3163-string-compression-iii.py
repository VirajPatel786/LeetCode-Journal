class Solution:
    def compressedString(self, word: str) -> str:
        """
        Compresses a string by replacing consecutive repeating characters with
        the character and the count of repeats (up to 9).

        Parameters:
        word (str): The string to be compressed.

        Returns:
        str: The compressed version of the string.
        """
        
        # Handle edge case of empty string
        if not word:
            return ""
        
        # Initialize the result list for efficient appending
        compressed = []
        count = 0  # Counter starts at 0
        current_char = word[0]  # Start with the first character

        # Iterate over the string, starting from the first character
        for i in range(len(word)):
            if word[i] == current_char and count < 9:
                # Increment count if current character is the same and count < 9
                count += 1
            else:
                # Append the compressed format (count + character) to the result
                compressed.append(str(count) + current_char)
                
                # Reset count to 1 for the new character sequence
                current_char = word[i]
                count = 1

        # Append the last character sequence
        compressed.append(str(count) + current_char)
        
        # Join the list into a single string and return
        return ''.join(compressed)
