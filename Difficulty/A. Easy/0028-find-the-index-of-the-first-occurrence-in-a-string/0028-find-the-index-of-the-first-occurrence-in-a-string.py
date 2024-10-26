class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """
        Finds the index of the first occurrence of needle in haystack,
        or returns -1 if needle is not part of haystack.

        Parameters:
        haystack (str): The main string where we search for the needle.
        needle (str): The substring we are looking for within haystack.

        Returns:
        int: The starting index of the first occurrence of needle in haystack,
             or -1 if needle is not found.
        """
        
        # Use the built-in find() method to locate the first occurrence
        # of needle in haystack. This method returns the index if found,
        # or -1 if the substring is not present in haystack.
        return haystack.find(needle)
