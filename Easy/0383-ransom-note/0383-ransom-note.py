class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for ch in ransomNote:
            if (ch not in magazine):
                return False
            magazine = magazine.replace(ch, "", 1)
        return True
