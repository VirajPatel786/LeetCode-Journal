class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        """
        Traverse the matrix diagonally and return the elements in diagonal order.

        Parameters:
        mat (List[List[int]]): The input matrix.

        Returns:
        List[int]: A list of elements in diagonal order.
        """
        if not mat or not mat[0]:
            return []
        
        m, n = len(mat), len(mat[0])
        result = []
        row, col = 0, 0
        direction = 1  # 1 means moving up-right, -1 means moving down-left
        
        for _ in range(m * n):
            result.append(mat[row][col])
            
            if direction == 1:  # Moving up-right
                if col == n - 1:  # Hit the last column, go down
                    row += 1
                    direction = -1
                elif row == 0:  # Hit the top row, go right
                    col += 1
                    direction = -1
                else:  # Continue moving up-right
                    row -= 1
                    col += 1
            else:  # Moving down-left
                if row == m - 1:  # Hit the last row, go right
                    col += 1
                    direction = 1
                elif col == 0:  # Hit the first column, go down
                    row += 1
                    direction = 1
                else:  # Continue moving down-left
                    row += 1
                    col -= 1
        
        return result
