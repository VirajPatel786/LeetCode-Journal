class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        location = {}
        letters = deque()
        
        # Collect letters and store positions of non-letter characters
        for i, j in enumerate(s):
            if not j.isalpha():
                location[i] = j
            else:
                letters.append(j)
        
        result = []
        for i in range(len(s)):
            if i in location:
                result.append(location[i])
            else:
                result.append(letters.pop())  # Pop from the right side (reversed order)
        
        return ''.join(result)