class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        """
        Finds the minimum number of groups required such that no two intervals in the same group overlap.

        Parameters:
        intervals (List[List[int]]): A list of intervals where each interval is represented as [left, right].

        Returns:
        int: The minimum number of groups required.
        """
        # Create a list of events: +1 for start, -1 for end + 1 (to avoid overlapping on the same end/start point)
        events = []
        for interval in intervals:
            events.append((interval[0], 1))  # Start of interval
            events.append((interval[1] + 1, -1))  # End of interval (+1 to handle inclusive intervals)
        
        # Sort events by time; if times are the same, process end events (-1) before start events (+1)
        events.sort()

        # Track the number of active intervals and the maximum at any time
        active_intervals = 0
        max_groups = 0

        # Process each event
        for event in events:
            active_intervals += event[1]  # Update active intervals based on event type
            max_groups = max(max_groups, active_intervals)  # Track the maximum number of groups needed
        
        return max_groups
