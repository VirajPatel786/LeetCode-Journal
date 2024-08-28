import heapq
from collections import defaultdict
from typing import List

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        # Build the graph using an adjacency list
        graph = defaultdict(list)
        for i in range(len(edges)):
            a, b = edges[i]
            prob = succProb[i]
            graph[a].append((b, prob))
            graph[b].append((a, prob))

        # Priority queue: stores (negative_probability, node)
        max_heap = [(-1.0, start_node)]
        # Probability to reach each node
        probabilities = [0.0] * n
        probabilities[start_node] = 1.0

        while max_heap:
            # Pop the node with the highest probability
            curr_prob, node = heapq.heappop(max_heap)
            curr_prob = -curr_prob  # Convert back to positive

            # If we reached the end node, return the probability
            if node == end_node:
                return curr_prob

            # Traverse neighbors
            for neighbor, prob in graph[node]:
                # Calculate the new probability through the current node
                new_prob = curr_prob * prob
                # If this new probability is better, update and push to the heap
                if new_prob > probabilities[neighbor]:
                    probabilities[neighbor] = new_prob
                    heapq.heappush(max_heap, (-new_prob, neighbor))

        # If end_node is unreachable
        return 0.0