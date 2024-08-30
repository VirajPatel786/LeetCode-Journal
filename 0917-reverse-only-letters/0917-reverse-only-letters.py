class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        # Collect all letters in the string
        letters = [c for c in s if c.isalpha()]
        
        # Create a result list to hold the final characters
        result = []
        
        # Iterate through the original string
        for c in s:
            # If the character is a letter, pop from the end of the letters list
            if c.isalpha():
                result.append(letters.pop())
            else:
                # If it's not a letter, just add it to the result as is
                result.append(c)
        
        # Join the list into a final string and return
        return ''.join(result)
