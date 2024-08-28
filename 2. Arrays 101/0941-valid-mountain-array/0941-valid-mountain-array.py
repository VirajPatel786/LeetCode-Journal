class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        if n < 3:
            return False

        i, j = 0, n - 1

        # Ascend to the peak
        while i < n - 1 and arr[i] < arr[i + 1]:
            i += 1

        # Descend to the peak
        while j > 0 and arr[j] < arr[j - 1]:
            j -= 1

        # Check if i and j meet at the peak and are not at the start or end
        return i == j and i != 0 and j != n - 1
            