class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        # Initialize values
        min1, min2 = float('inf'), float('inf')
        max1, max2 = float('-inf'), float('-inf')
        min1_idx, max1_idx = -1, -1
        
        for i, arr in enumerate(arrays):
            if arr[0] < min1:
                min2 = min1
                min1 = arr[0]
                min1_idx = i
            elif arr[0] < min2:
                min2 = arr[0]
            
            if arr[-1] > max1:
                max2 = max1
                max1 = arr[-1]
                max1_idx = i
            elif arr[-1] > max2:
                max2 = arr[-1]
        
        # Calculate the maximum distance excluding the case where both min and max are from the same array
        if min1_idx != max1_idx:
            return max1 - min1
        else:
            return max(max1 - min2, max2 - min1)