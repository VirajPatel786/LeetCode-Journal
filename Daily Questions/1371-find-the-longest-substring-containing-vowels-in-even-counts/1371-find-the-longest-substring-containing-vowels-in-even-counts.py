class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        """
        Finds the length of the longest substring where all vowels ('a', 'e', 'i', 'o', 'u') 
        appear an even number of times.
        
        :param s: str - Input string
        :return: int - Length of the longest valid substring with even vowel counts
        """
        
        # Mapping each vowel to a specific bit in the bitmask
        # Each vowel has a unique position in the 5-bit mask
        vowel_to_bit = {'a': 0, 'e': 1, 'i': 2, 'o': 3, 'u': 4}
        
        # Dictionary to store the first occurrence of each unique bitmask
        # Initialize with bitmask 0 (00000) at index -1, representing the start of the string
        seen = {0: -1}  # If we encounter a fully even state at any point, the substring is valid
        
        bitmask = 0  # A 5-bit number where each bit represents whether a vowel count is odd or even
                    # 00000 means all vowels have appeared an even number of times.
        
        max_len = 0  # Variable to store the length of the longest valid substring
        
        # Traverse the string and update the bitmask for each character
        for i, char in enumerate(s):
            # If the character is a vowel, toggle the corresponding bit in the bitmask
            # This toggles between even and odd counts of that vowel
            if char in vowel_to_bit:
                bitmask ^= (1 << vowel_to_bit[char])
            
            # Check if this bitmask has been seen before
            # If the same bitmask appears again, it means the substring between the two occurrences
            # has even counts of all vowels (since toggling makes it return to the same state)
            if bitmask in seen:
                # Calculate the length of the valid substring by finding the distance
                # between the current position and the first occurrence of this bitmask
                max_len = max(max_len, i - seen[bitmask])
            else:
                # If this bitmask hasn't been seen before, record its first occurrence
                seen[bitmask] = i
        
        return max_len
