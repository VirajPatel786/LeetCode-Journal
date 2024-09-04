class Solution:
    def getLucky(self, s: str, k: int) -> int:
        # Step 1: Convert each character in the string to its corresponding numeric value
        # ('a' -> 1, 'b' -> 2, ..., 'z' -> 26).
        numericS = ""
        for ch in s:
            numericS += str(ord(ch) - ord('a') + 1)  # Append the numeric value of each character
        
        # Step 2: Perform the transformation k times
        for _ in range(k):
            # Convert numericS (which is a string) to a list of digits, sum them, and assign it back to numericS
            numericS = sum(int(ch) for ch in numericS)  # Sum the digits of the numeric string
            
            # Update numericS as a string so it can be processed again in the next iteration (if k > 1)
            numericS = str(numericS)

        # Step 3: After k transformations, return the final result
        return int(numericS)  # Convert numericS back to an integer and return it
