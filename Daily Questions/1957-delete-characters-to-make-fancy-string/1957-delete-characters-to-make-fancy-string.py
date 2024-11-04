class Solution:
    def makeFancyString(self, s: str) -> str:
        """
        Modifies the input string `s` to a "fancy" string where no character appears more than twice in a row.

        Parameters:
        s (str): The input string containing lowercase English letters.

        Returns:
        str: A fancy string with no character appearing more than twice consecutively.
        """
        result = ""  # Initialize the result string to build the fancy string
        count = 0  # Counter to track consecutive occurrences of the current character

        # Iterate over each character in the input string
        for ch in s:
            if not result or ch != result[-1]:  # Start counting for new characters
                count = 1
            else:
                count += 1  # Increment counter for consecutive characters
            # Add character only if it appears less than three times consecutively
            if count < 3:
                result += ch

        return result
