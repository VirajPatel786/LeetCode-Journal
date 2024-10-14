class Solution:
    def shortestPalindrome(self, s: str) -> str:
        """
        Finds the shortest palindrome by adding characters in front of the string.
        
        :param s: Input string
        :return: The shortest palindrome
        """
        if len(s) <= 1:
            return s

        def compute_prefix(pattern: str) -> list:
            """
            KMP algorithm's prefix function to compute the longest prefix which is also a suffix.
            
            :param pattern: Input string to compute prefix array
            :return: List representing the KMP prefix table
            """
            n = len(pattern)
            prefix = [0] * n
            j = 0  # length of the previous longest prefix suffix

            for i in range(1, n):
                while j > 0 and pattern[i] != pattern[j]:
                    j = prefix[j - 1]
                if pattern[i] == pattern[j]:
                    j += 1
                prefix[i] = j
            return prefix

        # Create the temporary string
        temp = s + "#" + s[::-1]
        
        # Compute prefix array on the combined string
        prefix = compute_prefix(temp)
        
        # The length of the palindrome at the start of s is given by prefix[-1]
        max_palindrome_len = prefix[-1]
        
        # Add the remaining characters in reverse order to the start of s
        add_to_front = s[max_palindrome_len:][::-1]
        return add_to_front + s