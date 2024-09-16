from typing import List

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        """
        Given a list of time points in "HH:MM" format, return the minimum difference 
        in minutes between any two time points.
        
        :param timePoints: List[str] - A list of time points in "HH:MM" format.
        :return: int - The minimum time difference in minutes.
        """
        # Convert "HH:MM" to minutes since midnight
        def convert_to_minutes(time: str) -> int:
            hours, minutes = map(int, time.split(':'))
            return hours * 60 + minutes
        
        # Convert all time points to minutes and sort them
        minutes = sorted(convert_to_minutes(time) for time in timePoints)
        
        # Initialize the minimum difference as infinity
        min_diff = float('inf')
        
        # Compute the difference between consecutive time points
        for i in range(1, len(minutes)):
            min_diff = min(min_diff, minutes[i] - minutes[i - 1])
        
        # Calculate the circular difference between the last and the first time point
        # Since timePoints are in a 24-hour clock, we also need to compare the first and last
        circular_diff = 1440 + minutes[0] - minutes[-1]
        min_diff = min(min_diff, circular_diff)
        
        return min_diff
