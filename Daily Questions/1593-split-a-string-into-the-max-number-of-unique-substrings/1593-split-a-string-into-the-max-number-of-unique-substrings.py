class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        """
        Function to find the maximum number of unique substrings that the string can be split into.
        Optimized by pruning unnecessary recursion paths.
        
        Parameters:
        s (str): The input string.
        
        Returns:
        int: The maximum number of unique substrings.
        """
        def backtrack(start, seen):
            # If we have reached the end of the string, return 0 because no more splits are possible
            if start == len(s):
                return 0
            
            max_splits = 0
            
            # Pruning: If the current count + remaining length is less than or equal to the current max_splits, stop exploring.
            if len(seen) + len(s) - start <= max_splits:
                return max_splits
            
            # Try all possible substrings starting from index `start`
            for end in range(start + 1, len(s) + 1):
                substring = s[start:end]
                if substring not in seen:
                    # Add the substring to the set
                    seen.add(substring)
                    # Recurse for the remaining part of the string and count this split
                    max_splits = max(max_splits, 1 + backtrack(end, seen))
                    # Backtrack: Remove the substring from the set to explore other possibilities
                    seen.remove(substring)
            
            return max_splits
        
        return backtrack(0, set())
