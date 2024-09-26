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
        # Iterate through all existing events to check for overlap
        for time_start, time_end in self.events:
            # Overlap condition: if the new event starts before the existing event ends
            # and the new event ends after the existing event starts.
            if start < time_end and end > time_start:
                return False  # Return False if there is any overlap
        
        # If no overlap is found, add the new event to the list of events
        self.events.append([start, end])
        return True  # Return True as the event is successfully booked

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)