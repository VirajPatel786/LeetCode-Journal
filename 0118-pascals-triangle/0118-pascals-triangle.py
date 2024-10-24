class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        """
        Generate the first 'numRows' of Pascal's Triangle.

        Parameters:
        numRows (int): The number of rows of Pascal's Triangle to generate.

        Returns:
        List[List[int]]: A list of lists, where each inner list represents a row of Pascal's Triangle.
        """

        # Special case: If numRows is 1, return just the first row
        if numRows == 1:
            return [[1]]

        # Special case: If numRows is 2, return the first two rows
        if numRows == 2:
            return [[1], [1, 1]]

        # Initialize Pascal's Triangle with the first two rows
        pascal_triangle = [[1], [1, 1]]

        # Generate rows from the 3rd row onwards (index 2)
        for i in range(2, numRows):
            row = []  # Initialize the current row

            # Generate each value in the current row
            for j in range(i + 1):
                # The first and last values in each row are always 1
                if j == 0 or j == i:
                    row.append(1)
                else:
                    # Each value is the sum of the two values directly above it from the previous row
                    row.append(pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j])

            # Add the generated row to Pascal's Triangle
            pascal_triangle.append(row)

        # Return the full Pascal's Triangle
        return pascal_triangle
