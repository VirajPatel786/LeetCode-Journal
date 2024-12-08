from typing import List
from bisect import bisect_right

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        """
        Finds the maximum sum of values by choosing at most two non-overlapping events.

        Parameters:
        events (List[List[int]]): List of events where each event is [startTime, endTime, value].

        Returns:
        int: Maximum sum of values for at most two non-overlapping events.
        """
        # Step 1: Sort events by their end times
        events.sort(key=lambda x: x[1])
        
        # Step 2: Store the end times and values for binary search
        end_times = [event[1] for event in events]
        max_value = 0
        max_two_events = 0
        
        # Step 3: Track the maximum value seen so far
        max_values = []
        for _, _, value in events:
            max_value = max(max_value, value)
            max_values.append(max_value)
        
        # Step 4: Iterate through each event to find the best combination
        for i, (start, end, value) in enumerate(events):
            # Binary search to find the latest event that ends before the current event starts
            idx = bisect_right(end_times, start - 1)
            if idx > 0:
                max_two_events = max(max_two_events, value + max_values[idx - 1])
            else:
                max_two_events = max(max_two_events, value)
        
        return max_two_events
