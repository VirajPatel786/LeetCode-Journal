import heapq

class Solution:
    def smallestRange(self, nums):
        """
        Find the smallest range that includes at least one number from each list.

        Parameters:
        nums (List[List[int]]): List of sorted lists.

        Returns:
        List[int]: Smallest range [a, b].
        """
        min_heap = []
        current_max = float('-inf')

        # Initialize the heap with the first element of each list
        for i in range(len(nums)):
            heapq.heappush(min_heap, (nums[i][0], i, 0))
            current_max = max(current_max, nums[i][0])

        best_range = [-float('inf'), float('inf')]

        # Process the heap
        while min_heap:
            min_val, list_idx, elem_idx = heapq.heappop(min_heap)

            # Update the best range if the current range is smaller
            if current_max - min_val < best_range[1] - best_range[0]:
                best_range = [min_val, current_max]

            # If there's a next element in the current list, add it to the heap
            if elem_idx + 1 < len(nums[list_idx]):
                next_val = nums[list_idx][elem_idx + 1]
                heapq.heappush(min_heap, (next_val, list_idx, elem_idx + 1))
                current_max = max(current_max, next_val)
            else:
                # If any list is exhausted, we stop
                break

        return best_range
