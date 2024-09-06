class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        changeList = [0, 0]
        for bill in bills:
            if bill == 5:
                changeList[0] += 1
            elif bill == 10:
                changeList[1] += 1
                changeList[0] -= 1
            else:
                if changeList[1] > 0:
                    changeList[1] -= 1
                    changeList[0] -= 1
                else:
                    changeList[0] -= 3
            if changeList[0] < 0:
                return False
        return True

        