from typing import List

class Solution:
    def stringSequence(self, target: str) -> List[str]:
        """
        Generates the sequence of strings that appear on the screen as Alice types the target string.
        
        Parameters:
        target (str): The target string Alice is typing.
        
        Returns:
        List[str]: The list of all strings that appear on the screen in the order they appear.
        """
        result = []  # List to store the sequence of strings that appear on the screen
        str_on_screen = ""  # String that represents what's currently on the screen
        
        for i in range(len(target)):
            # Step 1: Append 'a' to the current string (Key 1 action)
            str_on_screen += 'a'
            result.append(str_on_screen)  # Add the string after pressing Key 1
            
            # Step 2: Change the last character (Key 2 actions) until it matches target[i]
            while str_on_screen[-1] != target[i]:
                # Increment the last character using Key 2
                str_on_screen = str_on_screen[:-1] + chr(ord(str_on_screen[-1]) + 1)
                result.append(str_on_screen)  # Add the string after each Key 2 press
        
        return result
