from typing import List

class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        """
        Finds the unique champion team in a tournament if it exists.

        Parameters:
        n (int): Number of teams (nodes).
        edges (List[List[int]]): Directed edges representing team strengths.

        Returns:
        int: The team number of the champion, or -1 if no unique champion exists.
        """
        # Step 1: Initialize the in-degree array
        in_degree = [0] * n
        
        # Step 2: Populate the in-degree array based on edges
        for u, v in edges:
            in_degree[v] += 1

        # Step 3: Find nodes with in-degree 0
        candidates = [i for i in range(n) if in_degree[i] == 0]

        # Step 4: Check for a unique champion
        return candidates[0] if len(candidates) == 1 else -1
