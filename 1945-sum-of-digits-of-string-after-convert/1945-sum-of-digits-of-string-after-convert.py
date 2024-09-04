class Solution:
    def getLucky(self, s: str, k: int) -> int:
        numericS = ""
        for ch in s:
            numericS += str(ord(ch) - ord('a') + 1)
        result = 0
        while (k > 0):
            numericS = sum([int(ch) for ch in numericS])
            result = numericS
            numericS = str(numericS)
            k -= 1
        return result

        