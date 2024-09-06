class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        s = list(s)  # Convert the string to a list for mutability
        left, right = 0, len(s) - 1
        
        while left < right:
            # Move the left pointer until it points to a letter
            if not s[left].isalpha():
                left += 1
            # Move the right pointer until it points to a letter
            elif not s[right].isalpha():
                right -= 1
            else:
                # Swap the letters at left and right pointers
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1
        
        return ''.join(s)  # Convert the list back to a string