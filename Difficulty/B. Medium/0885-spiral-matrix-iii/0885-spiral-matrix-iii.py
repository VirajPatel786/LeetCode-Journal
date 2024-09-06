class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # right, down, left, up
        step = 1  # the current step length in the current direction
        direction_index = 0  # index for directions
        result = list()
        count = rows * cols
        
        while count > 0:
            for _ in range(2):  # there are two moves for each step length in a given direction
                for _ in range(step):
                    if 0 <= rStart < rows and 0 <= cStart < cols:
                        result.append([rStart, cStart])
                        count -= 1
                    rStart += directions[direction_index][0]
                    cStart += directions[direction_index][1]
                direction_index = (direction_index + 1) % 4  # change direction
            step += 1  # increase step length after two direction changes
        
        return result
        