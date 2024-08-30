class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        revS = []
        start, end = 0, len(s) - 1
        
        while start < len(s):
            if not s[start].isalpha():
                # If the character at 'start' is not a letter, add it to result and move start pointer
                revS.append(s[start])
                start += 1
            elif not s[end].isalpha():
                # If the character at 'end' is not a letter, move end pointer to the left
                end -= 1
            else:
                # If both characters are letters, add the letter at 'end' to the result
                revS.append(s[end])
                start += 1
                end -= 1
        
        return ''.join(revS)