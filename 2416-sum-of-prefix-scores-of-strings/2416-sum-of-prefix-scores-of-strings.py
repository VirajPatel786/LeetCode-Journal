class TrieNode:
    """
    TrieNode represents a single node in the Trie.
    Each node contains:
    - children: A dictionary to store child nodes corresponding to each character.
    - count: An integer that keeps track of how many words pass through this node.
    """
    def __init__(self):
        self.children = {}  # Dictionary to store child TrieNodes for each character.
        self.count = 0  # Count of words passing through this node.

class Trie:
    """
    Trie is a data structure used for efficiently storing strings and their prefixes.
    It supports the following operations:
    - insert: To insert a word into the Trie.
    - calculate_prefix_score: To calculate the total score of all prefixes of a given word.
    """
    def __init__(self):
        # Initialize the root of the Trie
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the Trie. As the word is inserted, it increments the count for each prefix.

        Parameters:
        word (str): The word to insert into the Trie.
        """
        node = self.root
        for char in word:
            # If the character is not in the current node's children, create a new node.
            if char not in node.children:
                node.children[char] = TrieNode()
            # Move to the next node in the Trie
            node = node.children[char]
            # Increment the count to indicate this prefix is part of another word.
            node.count += 1

    def calculate_prefix_score(self, word):
        """
        Calculates the sum of scores for every prefix of a given word.
        The score of each prefix is the number of words that have that prefix.

        Parameters:
        word (str): The word for which to calculate the prefix score.

        Returns:
        int: The sum of the scores of all prefixes of the word.
        """
        node = self.root
        total_score = 0  # Initialize total score to 0
        for char in word:
            # Move to the next node for the current character
            node = node.children[char]
            # Add the count at the current node to the total score
            total_score += node.count
        return total_score

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        """
        Calculates the sum of prefix scores for each word in the input list.

        Parameters:
        words (List[str]): List of words to compute prefix scores for.

        Returns:
        List[int]: A list of integers where each element is the sum of prefix scores of a corresponding word.
        """
        # Initialize the Trie
        trie = Trie()

        # Insert all words into the Trie
        for word in words:
            trie.insert(word)

        # Calculate prefix scores for each word
        result = []
        for word in words:
            # For each word, compute its prefix score using the Trie
            result.append(trie.calculate_prefix_score(word))

        return result