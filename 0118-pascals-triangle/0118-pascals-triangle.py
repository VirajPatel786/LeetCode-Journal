class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        """
        Generate the first 'numRows' of Pascal's Triangle.
        
        Parameters:
        numRows (int): The number of rows of Pascal's Triangle to generate.

        Returns:
        List[List[int]]: A list of lists, where each inner list represents a row of Pascal's Triangle.
        """

        # Initialize Pascal's Triangle as an empty list to store the rows
        pascal_triangle = []

        # Iterate over the number of rows to generate
        for i in range(numRows):
            # Start each row with 1 (first element is always 1)
            row = [1] * (i + 1)
            
            # For each row, calculate values in between the first and last 1's
            for j in range(1, i):
                # row[j] is the sum of the two elements from the previous row
                row[j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j]
            
            # Append the row to Pascal's Triangle
            pascal_triangle.append(row)

        return pascal_triangle
