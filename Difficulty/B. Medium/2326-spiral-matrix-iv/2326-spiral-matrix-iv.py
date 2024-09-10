# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        # Initialize the matrix with -1 values
        result = [[-1 for _ in range(n)] for _ in range(m)]
        
        # Boundaries for the spiral traversal
        top, bottom, left, right = 0, m - 1, 0, n - 1
        
        # Pointer to traverse the linked list
        current = head
        
        # Continue filling the matrix while there are elements in the linked list and space in the matrix
        while current and top <= bottom and left <= right:
            # Fill the top row (left to right)
            for j in range(left, right + 1):
                if current:
                    result[top][j] = current.val
                    current = current.next
            top += 1  # Move the top boundary down

            # Fill the right column (top to bottom)
            for i in range(top, bottom + 1):
                if current:
                    result[i][right] = current.val
                    current = current.next
            right -= 1  # Move the right boundary left

            # Fill the bottom row (right to left)
            if top <= bottom:
                for j in range(right, left - 1, -1):
                    if current:
                        result[bottom][j] = current.val
                        current = current.next
                bottom -= 1  # Move the bottom boundary up

            # Fill the left column (bottom to top)
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    if current:
                        result[i][left] = current.val
                        current = current.next
                left += 1  # Move the left boundary right

        return result