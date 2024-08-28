class Solution:
    def minimumPushes(self, word: str) -> int:
        #from Collections import Counter
        key_list_count = [0, 8, 8, 8, 3]
        count_word_list = sorted([(v, k) for k, v in Counter(word).items()], reverse=True)
        cost = 0
        i = 1
        for v, k in count_word_list:
            if (key_list_count[i]>0):
                cost += v * i
                key_list_count[i] -= 1
            if (key_list_count[i]==0):
                i += 1
        return cost
        