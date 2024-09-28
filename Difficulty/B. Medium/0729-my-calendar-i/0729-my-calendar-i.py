from bisect import bisect_left

class MyCalendar:
    """
    A class to manage booking of events where no two events should overlap.
    """

    def __init__(self):
        """
        Initializes an empty list to store booked events.
        Each event is represented as a list of two integers: [start, end].
        """
        self.events = []

    def book(self, start: int, end: int) -> bool:
        """
        Books a new event if it does not overlap with existing events.
        
        Parameters:
        start (int): The start time of the new event.
        end (int): The end time of the new event (exclusive).
        
        Returns:
        bool: True if the event is successfully booked (i.e., no overlap),
              False if there is an overlap with an existing event.
        """
        # Find the insertion point for the new event's start time
        index = bisect_left(self.events, [start, end])

        # Check if the new event overlaps with the previous event
        if index > 0 and self.events[index - 1][1] > start:
            return False
        
        # Check if the new event overlaps with the next event
        if index < len(self.events) and self.events[index][0] < end:
            return False

        # Insert the new event into the sorted list
        self.events.insert(index, [start, end])
        return True

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)