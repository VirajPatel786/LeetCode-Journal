import heapq
from typing import List, Tuple

class Solution:
    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        # Step 1: Build the adjacency list from the edge list
        adjacency_list = [[] for _ in range(n)]
        for i, (u, v, w) in enumerate(edges):
            adjacency_list[u].append((v, i))  # Append (neighbor, edge_index)
            adjacency_list[v].append((u, i))  # Graph is undirected

        # Step 2: Initialize distances for two Dijkstra runs
        # distances[node][0] is for the first run (all -1 edges set to 1)
        # distances[node][1] is for the second run (with modifications)
        distances = [[float('inf')] * 2 for _ in range(n)]
        distances[source][0] = distances[source][1] = 0

        # Step 3: Run Dijkstra's algorithm for the first time, treating -1 weights as 1
        self.run_dijkstra(adjacency_list, edges, distances, source, 0, 0)
        # Calculate the difference needed to reach the target distance
        difference = target - distances[destination][0]

        # If the current shortest path is already longer than the target, return []
        if difference < 0:
            return []

        # Step 4: Run Dijkstra's algorithm a second time, adjusting -1 weights to match the target
        self.run_dijkstra(adjacency_list, edges, distances, source, difference, 1)

        # If even after adjustments the path is not equal to the target, return []
        if distances[destination][1] < target:
            return []

        # Step 5: Final adjustment - set all remaining -1 edges to 1
        for edge in edges:
            if edge[2] == -1:
                edge[2] = 1

        return edges

    def run_dijkstra(self, adjacency_list: List[List[Tuple[int, int]]], edges: List[List[int]], distances: List[List[int]], source: int, difference: int, run: int):
        n = len(adjacency_list)
        # Priority queue for Dijkstra's algorithm
        priority_queue = [(0, source)]  # (current_distance, node)
        distances[source][run] = 0

        while priority_queue:
            current_distance, current_node = heapq.heappop(priority_queue)
            if current_distance > distances[current_node][run]:
                continue  # Ignore outdated entries in the priority queue

            # Explore all neighbors of the current node
            for next_node, edge_index in adjacency_list[current_node]:
                weight = edges[edge_index][2]

                # For -1 weights, use 1 as a temporary weight
                if weight == -1:
                    weight = 1

                # In the second run, adjust the weight if needed
                if run == 1 and edges[edge_index][2] == -1:
                    # Calculate the required weight adjustment
                    new_weight = difference + distances[next_node][0] - distances[current_node][1]
                    if new_weight > weight:
                        edges[edge_index][2] = weight = new_weight

                # Relaxation step - update the shortest distance if we found a shorter path
                if distances[next_node][run] > distances[current_node][run] + weight:
                    distances[next_node][run] = distances[current_node][run] + weight
                    heapq.heappush(priority_queue, (distances[next_node][run], next_node))
