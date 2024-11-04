class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""
        count = 1
        ch = word[0]
        for i in range(1, len(word)):
            if ch == word[i] and count < 9:
                count += 1
            else:
                comp += str(count) + ch
                ch = word[i]
                count = 1
        comp += str(count) + ch
        return comp
