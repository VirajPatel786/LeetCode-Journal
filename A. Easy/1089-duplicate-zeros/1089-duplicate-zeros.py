class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        arrLength = len(arr)
        listIndex = list()
        for i in range(arrLength):
            if (arr[i] == 0):
                listIndex.append(i)
        count = 0
        for index in listIndex:
            arr.insert(index + count, 0)
            count += 1
        for i in range(count):
            arr.pop()


        