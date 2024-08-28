class Solution:
    def nearestPalindromic(self, n: str) -> str:
        length = len(n)
        if length == 1:
            return str(int(n) - 1)

        candidates = set()

        # Edge cases: 10...01 -> 9...9 or 1...1
        candidates.add(str(10**(length - 1) - 1))
        candidates.add(str(10**length + 1))

        # Build the prefix
        prefix = int(n[:(length + 1) // 2])

        for i in [-1, 0, 1]:
            # Create palindrome by mirroring
            candidate = str(prefix + i)
            if length % 2 == 0:
                candidate = candidate + candidate[::-1]
            else:
                candidate = candidate + candidate[-2::-1]
            candidates.add(candidate)

        # Remove the original number itself
        candidates.discard(n)

        # Find the closest palindrome
        closest = min(candidates, key=lambda x: (abs(int(x) - int(n)), int(x)))

        return closest