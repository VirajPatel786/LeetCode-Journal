class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def checkGridMagic(grid: List[List[int]]) -> bool:
            flattenedGridSet = set([num for row in grid for num in row])
            if flattenedGridSet != set([1, 2, 3, 4, 5, 6, 7, 8, 9]):
                return False
            gridRowSum = [sum(row) for row in grid]
            gridColSum = [sum(col) for col in zip(*grid)]
            gridDiagSum = list()
            gridDiagSum.append(sum(grid[i][i] for i in range(3)))
            gridDiagSum.append(sum(grid[i][2 - i] for i in range(3)))
            gridRowColDiagSum = gridRowSum + gridColSum + gridDiagSum
            return all(x == gridRowColDiagSum[0] for x in gridRowColDiagSum)

        gridCount = 0
        checkSum = sum(range(10))
        for i in range(len(grid)-2):
            for j in range(len(grid[i])-2):
                subGrid = [row[j:j+3] for row in grid[i:i+3]]
                if checkGridMagic(subGrid):
                    gridCount += 1
        return gridCount

