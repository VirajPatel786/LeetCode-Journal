# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        # Initialize the matrix with -1 values
        result = [[-1 for _ in range(n)] for _ in range(m)]
        
        # Directions: right (0,1), down (1,0), left (0,-1), up (-1,0)
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        # Initial position and direction (starting at the top-left corner)
        i, j, d = 0, 0, 0  # (row, column, direction index)
        
        # Pointer to traverse the linked list
        current = head

        # We'll fill m * n cells (each cell of the matrix)
        for _ in range(m * n):
            # Fill current position with the linked list value or -1 if list is exhausted
            if current:
                result[i][j] = current.val
                current = current.next
            else:
                result[i][j] = -1  # If the linked list ends, we put -1

            # Determine the next cell position
            ni, nj = i + directions[d][0], j + directions[d][1]
            
            # Check if the next position is within bounds and not yet filled
            if 0 <= ni < m and 0 <= nj < n and result[ni][nj] == -1:
                i, j = ni, nj  # Move to the next valid position
            else:
                # Change direction (cycle through right, down, left, up)
                d = (d + 1) % 4
                i, j = i + directions[d][0], j + directions[d][1]  # Move in the new direction

        return result