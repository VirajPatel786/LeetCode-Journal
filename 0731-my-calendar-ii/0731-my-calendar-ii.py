import bisect

class MyCalendarTwo:
    """
    A calendar system that allows event bookings and prevents triple bookings.

    The MyCalendarTwo class allows users to book events on a calendar, ensuring
    that no three events overlap at any given time.
    """
    
    def __init__(self):
        """
        Initializes the MyCalendarTwo object with two lists:
        
        - single_booked: Stores intervals that represent single bookings.
        - double_booked: Stores intervals where double bookings have occurred.
        """
        self.single_booked = []  # Stores single bookings in sorted order
        self.double_booked = []  # Stores double bookings in sorted order

    def get_overlapping_intervals(self, intervals, start, end):
        """
        Finds the overlapping intervals in the given intervals list with the range [start, end).

        Parameters:
        intervals (list): A list of intervals (flattened) that represent bookings.
        start (int): The start time of the new booking.
        end (int): The end time of the new booking.

        Returns:
        list: A list of overlapping intervals.
        """
        left_index = bisect.bisect_left(intervals, start)
        right_index = bisect.bisect_right(intervals, end)
        
        overlapping_intervals = []
        
        # Handle the case where the left bound is within an interval
        if left_index % 2:
            if intervals[left_index] != start:
                overlapping_intervals.append(start)
            else:
                left_index += 1

        overlapping_intervals += intervals[left_index:right_index]

        # Handle the case where the right bound is within an interval
        if right_index % 2:
            if intervals[right_index - 1] != end:
                overlapping_intervals.append(end)
            else:
                overlapping_intervals.pop()

        return overlapping_intervals
        
    def add_interval(self, intervals, start, end):
        """
        Adds the new interval [start, end) to the given intervals list, maintaining the order.

        Parameters:
        intervals (list): A list of intervals (flattened) that represent bookings.
        start (int): The start time of the new booking.
        end (int): The end time of the new booking.
        """
        left_index = bisect.bisect_left(intervals, start)
        right_index = bisect.bisect_right(intervals, end)
        
        new_intervals = []
        
        # Add the start boundary if it's outside of any existing interval
        if left_index % 2 == 0:
            new_intervals.append(start)
            
        # Add the end boundary if it's outside of any existing interval
        if right_index % 2 == 0:
            new_intervals.append(end)

        # Replace the affected range with the new intervals
        intervals[left_index:right_index] = new_intervals

    def book(self, start: int, end: int) -> bool:
        """
        Attempts to book a new event in the calendar.

        The function checks if the new event overlaps with any double-booked
        intervals. If it does, the booking is rejected to prevent a triple booking.
        If the booking only overlaps with single bookings, it is allowed, and any
        new double-booking intervals are added to the double_booked list.

        Parameters:
        start (int): The start time of the event (inclusive).
        end (int): The end time of the event (exclusive).

        Returns:
        bool: Returns True if the booking is successful and does not cause a triple
              booking. Returns False if the booking would result in a triple booking.
        """
        # Check if the new booking would result in a triple booking
        if self.get_overlapping_intervals(self.double_booked, start, end):
            return False
        
        # Find overlaps with single bookings
        overlapping_single_intervals = self.get_overlapping_intervals(self.single_booked, start, end)

        # If there's an overlap with single bookings, add those overlapping intervals to double_booked
        if overlapping_single_intervals:
            for i in range(0, len(overlapping_single_intervals), 2):
                overlap_start = overlapping_single_intervals[i]
                overlap_end = overlapping_single_intervals[i + 1]
                self.add_interval(self.double_booked, overlap_start, overlap_end)

        # Add the new event to single_booked
        self.add_interval(self.single_booked, start, end)

        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)