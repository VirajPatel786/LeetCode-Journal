class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        sorted_times = sorted(times, key = lambda x : x[0])
        chairs = list()
        for arrival, leaving in sorted_times:
            for i in range(len(chairs)):
                if chairs[i] <= arrival:
                    chairs[i] = -1
            try:
                empty_chair_index = chairs.index(-1)
            except ValueError:
                empty_chair_index = -1
            if len(chairs) == 0 or empty_chair_index == -1:
                chairs.append(leaving)
            else:
                chairs[empty_chair_index] = leaving
            #print(chairs)
            if targetFriend == times.index([arrival, leaving]):
                if empty_chair_index == -1:
                    return len(chairs) - 1
                else:
                    return empty_chair_index