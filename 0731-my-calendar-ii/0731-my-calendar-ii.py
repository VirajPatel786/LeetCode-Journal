from bisect import bisect_left

class MyCalendarTwo:
    """
    A calendar system that allows event bookings and prevents triple bookings.

    The MyCalendarTwo class allows users to book events on a calendar, ensuring
    that no three events overlap at any given time.
    """
    
    def __init__(self):
        """
        Initializes the MyCalendarTwo object with two lists:
        
        - booked: Stores intervals that represent single bookings.
        - overlaps: Stores intervals where double bookings have occurred.
        """
        # List to store single bookings
        self.booked = []
        # List to store double bookings (overlaps of single bookings)
        self.overlaps = []

    def book(self, start: int, end: int) -> bool:
        """
        Attempts to book a new event in the calendar.

        The function checks if the new event overlaps with any double-booked
        intervals (stored in overlaps). If it does, the booking is rejected to
        prevent a triple booking. If the booking only overlaps with single bookings,
        it is allowed, and any new double-booking intervals are added to the overlaps
        list.

        Parameters:
        start (int): The start time of the event (inclusive).
        end (int): The end time of the event (exclusive).

        Returns:
        bool: Returns True if the booking is successful and does not cause a triple
              booking. Returns False if the booking would result in a triple booking.
        """
        # Check if there is a conflict with double bookings using binary search
        i = bisect_left(self.overlaps, (start, end))
        for j in range(max(i - 1, 0), min(i + 1, len(self.overlaps))):
            os, oe = self.overlaps[j]
            if max(start, os) < min(end, oe):
                return False

        # Find and store the overlap between the new booking and existing single bookings using binary search
        i = bisect_left(self.booked, (start, end))
        for j in range(max(i - 1, 0), min(i + 1, len(self.booked))):
            bs, be = self.booked[j]
            if max(start, bs) < min(end, be):
                self.overlaps.append((max(start, bs), min(end, be)))

        # Insert the event in sorted order in single bookings
        self.booked.insert(i, (start, end))
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)