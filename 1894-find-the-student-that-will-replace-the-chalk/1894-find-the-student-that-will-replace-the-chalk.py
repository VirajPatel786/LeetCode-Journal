class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        # Calculate the total amount of chalk required for one complete round.
        sumChalk = sum(chalk)
        
        # Find the remainder of chalk after completing full rounds within the total k.
        # This remainder represents the amount of chalk left after simulating full rounds.
        remainder = k % sumChalk
        
        # Initialize an index variable to track the current student.
        i = 0
        
        # Iterate through the list of chalk usage per student.
        while i < len(chalk):
            # Subtract the current student's chalk usage from the remainder.
            remainder -= chalk[i]
            
            # If the remainder becomes negative, it means the current student will run out of chalk.
            if remainder < 0:
                return i  # Return the index of the student who needs more chalk.
            
            # Move to the next student.
            i += 1
