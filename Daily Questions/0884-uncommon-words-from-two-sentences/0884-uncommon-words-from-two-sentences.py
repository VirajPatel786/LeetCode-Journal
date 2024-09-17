from collections import Counter
from typing import List

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        """
        Find words that appear exactly once across both sentences.
        
        :param s1: str - The first sentence as a string.
        :param s2: str - The second sentence as a string.
        :return: List[str] - A list of words that appear exactly once across both sentences.
        """
        # Combine both sentences, split into words, and count the frequency of each word
        combined_counter = Counter((s1 + " " + s2).split())
        
        # Return words that have a frequency of exactly one
        return [word for word, count in combined_counter.items() if count == 1]
