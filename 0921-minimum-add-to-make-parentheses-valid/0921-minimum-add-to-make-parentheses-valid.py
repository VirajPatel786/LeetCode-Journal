class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_parentheses = 0
        close_parentheses = 0
        for ch in s:
            if ch == '(':
                open_parentheses += 1
            elif ch == ')' and open_parentheses > 0:
                open_parentheses -= 1
            else:
                close_parentheses += 1
        return open_parentheses + close_parentheses