from typing import List

class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        """
        Rotates the box 90 degrees clockwise after simulating gravity.

        Parameters:
        box (List[List[str]]): The m x n matrix representing the box.

        Returns:
        List[List[str]]: The rotated n x m matrix.
        """
        m, n = len(box), len(box[0])
        
        # Simulate gravity for each row
        for row in box:
            empty_position = n - 1  # Start from the rightmost position
            for col in range(n - 1, -1, -1):
                if row[col] == '#':  # Stone
                    # Move stone to the lowest available position
                    row[col], row[empty_position] = row[empty_position], row[col]
                    empty_position -= 1
                elif row[col] == '*':  # Obstacle
                    # Reset the empty position
                    empty_position = col - 1
        
        # Rotate the box 90 degrees clockwise
        rotated_box = [[box[m - 1 - r][c] for r in range(m)] for c in range(n)]
        
        return rotated_box
