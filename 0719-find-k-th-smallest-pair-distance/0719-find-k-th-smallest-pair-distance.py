class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        # Sort the numbers to make pair distance calculation easier
        nums.sort()
        
        def countPairs(max_distance: int) -> int:
            # This function returns the number of pairs with a distance <= max_distance
            count = 0
            start = 0
            for i in range(len(nums)):
                # Find the rightmost pair (nums[i], nums[j]) such that nums[j] - nums[i] <= max_distance
                while start < len(nums) and nums[i] - nums[start] > max_distance:
                    start += 1
                count += i - start
            return count
        
        # Binary search on the distance
        low, high = 0, nums[-1] - nums[0]
        
        while low < high:
            mid = (low + high) // 2
            if countPairs(mid) < k:
                low = mid + 1
            else:
                high = mid
        
        return low
        