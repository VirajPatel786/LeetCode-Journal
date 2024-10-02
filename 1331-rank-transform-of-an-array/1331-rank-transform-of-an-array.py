class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        arr_copy = sorted(set(arr))
        for i in range(len(arr)):
            arr[i] = arr_copy.index(arr[i]) + 1
        return arr