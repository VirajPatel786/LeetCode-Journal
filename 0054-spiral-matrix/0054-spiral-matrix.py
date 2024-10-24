class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        """
        Return all elements of the matrix in spiral order.
        
        Parameters:
        matrix (List[List[int]]): The input matrix.

        Returns:
        List[int]: A list of elements in spiral order.
        """
        result = list()
        if not matrix:  # If the matrix is empty, return an empty list
            return result
        
        # Initialize the boundaries of the matrix
        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1
        
        while top <= bottom and left <= right:
            # Traverse from left to right along the top row
            for col in range(left, right + 1):
                result.append(matrix[top][col])
            top += 1  # Move the top boundary down
            
            # Traverse from top to bottom along the right column
            for row in range(top, bottom + 1):
                result.append(matrix[row][right])
            right -= 1  # Move the right boundary left
            
            if top <= bottom:
                # Traverse from right to left along the bottom row
                for col in range(right, left - 1, -1):
                    result.append(matrix[bottom][col])
                bottom -= 1  # Move the bottom boundary up
            
            if left <= right:
                # Traverse from bottom to top along the left column
                for row in range(bottom, top - 1, -1):
                    result.append(matrix[row][left])
                left += 1  # Move the left boundary right
        
        return result
