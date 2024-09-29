class Solution:
    def partitionString(self, s: str) -> int:
        count = 0
        prev_substring = ""
        for ch in s:
            if ch not in prev_substring:
                prev_substring += ch
            else:
                print(prev_substring)
                count += 1
                prev_substring = ch
        return count + 1