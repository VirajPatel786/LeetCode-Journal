from typing import List
import heapq

class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        """
        Determines which chair the target friend will sit in.

        Parameters:
        times (List[List[int]]): A list where each sublist contains the arrival 
                                 and leaving time of a friend.
        targetFriend (int): Index of the target friend.

        Returns:
        int: The index of the chair the target friend will sit in.
        """
        n = len(times)
        
        # Add an index to each friend's time for easy tracking
        events = [(arrival, leaving, i) for i, (arrival, leaving) in enumerate(times)]
        
        # Sort events by arrival time
        events.sort(key=lambda x: x[0])

        # Min-heap for available chairs (by index)
        available_chairs = list(range(n))
        heapq.heapify(available_chairs)
        
        # Min-heap to track when chairs will be available again (departure time, chair index)
        occupied_chairs = []

        # Iterate over each friend's arrival and leaving time
        for arrival, leaving, friend in events:
            # Free up any chairs where the friend has already left by the current arrival time
            while occupied_chairs and occupied_chairs[0][0] <= arrival:
                _, chair_index = heapq.heappop(occupied_chairs)
                heapq.heappush(available_chairs, chair_index)

            # Assign the friend the next available chair
            chair_index = heapq.heappop(available_chairs)
            heapq.heappush(occupied_chairs, (leaving, chair_index))

            # If this is the target friend, return the chair index
            if friend == targetFriend:
                return chair_index
