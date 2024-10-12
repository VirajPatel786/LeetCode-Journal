class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        """
        Finds the minimum number of groups required such that no two intervals in the same group overlap.

        Parameters:
        intervals (List[List[int]]): A list of intervals where each interval is represented as [left, right].

        Returns:
        int: The minimum number of groups required.
        """
        events = []

        # Create events for each interval's start and end. 
        # We use 'start' for the beginning of the interval and 'end' for the end of the interval.
        for interval in intervals:
            # Record the start of the interval
            events.append((interval[0], 'start'))
            # Record the end of the interval (+1 to indicate it's just after the interval ends)
            events.append((interval[1] + 1, 'end'))

        # Sort the events by time.
        # If two events have the same time, 'end' comes before 'start' to handle end of one interval before the start of another.
        events.sort()

        # Variables to track the number of active intervals and the maximum number of overlaps (i.e., groups).
        active_intervals = 0
        max_groups = 0

        # Process each event in order.
        for event in events:
            if event[1] == 'start':
                # If it's a start event, increment active intervals.
                active_intervals += 1
                # Update the maximum groups required.
                max_groups = max(max_groups, active_intervals)
            else:
                # If it's an end event, decrement active intervals.
                active_intervals -= 1

        # Return the maximum number of active intervals at any point, which is the number of groups needed.
        return max_groups
