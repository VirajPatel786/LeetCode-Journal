class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        prev_sn = '0'
        sn = ''
        for i in range(n):
            sn = prev_sn + '1' + self.invert(prev_sn)[::-1]
            prev_sn = sn
        return sn[k - 1]

    def invert(self, s: str) -> str:
        result = ""
        for ch in s:
            if ch == '0':
                result += '1'
            else:
                result += '0'
        return result