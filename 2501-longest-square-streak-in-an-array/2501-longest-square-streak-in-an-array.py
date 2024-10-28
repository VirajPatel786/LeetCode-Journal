class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        nums_set = set(nums)
        nums.sort()
        square_streaks = list()
        max_num = nums[-1]
        for i in range(len(nums) - 1):
            sub_streak = list()
            num = nums[i]
            sub_streak.append(num)
            for _ in range(5):
                if num <= max_num and num ** 2 in nums_set:
                    num = num ** 2
                    sub_streak.append(num)
            if len(sub_streak) == 5:
                return 5
            square_streaks.append(sub_streak)
        max_streak = max([len(streak) for streak in square_streaks])
        if max_streak == 1:
            return -1
        else:
            return max_streak
            
        