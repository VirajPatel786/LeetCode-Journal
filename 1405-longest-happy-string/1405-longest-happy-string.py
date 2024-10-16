from heapq import heappush, heappop

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        """
        Generate the longest happy string containing at most a 'a's, b 'b's, and c 'c's.
        
        Parameters:
        a (int): Number of 'a' characters available.
        b (int): Number of 'b' characters available.
        c (int): Number of 'c' characters available.
        
        Returns:
        str: The longest happy string that can be generated.
        """
        # Max heap to always pick the character with the most count left
        heap = []
        
        # Push negative values because Python's heapq is a min-heap by default
        if a > 0:
            heappush(heap, (-a, 'a'))
        if b > 0:
            heappush(heap, (-b, 'b'))
        if c > 0:
            heappush(heap, (-c, 'c'))
        
        result = []
        
        while heap:
            # Get the most frequent character
            count1, char1 = heappop(heap)
            
            # If the last two characters in result are the same as char1, we need to use another character
            if len(result) > 1 and result[-1] == result[-2] == char1:
                if not heap:
                    break  # No other character is available, exit
                count2, char2 = heappop(heap)
                result.append(char2)
                if count2 + 1 < 0:
                    heappush(heap, (count2 + 1, char2))  # Add it back with one less count
                heappush(heap, (count1, char1))  # Push the first character back into the heap
            else:
                # Append the current character to the result
                result.append(char1)
                if count1 + 1 < 0:
                    heappush(heap, (count1 + 1, char1))  # Add it back with one less count
        
        return ''.join(result)