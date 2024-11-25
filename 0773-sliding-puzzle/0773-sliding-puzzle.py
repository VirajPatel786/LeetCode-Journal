from typing import List
from collections import deque

class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        """
        Solves the sliding puzzle using BFS to find the shortest path.

        Parameters:
        board (List[List[int]]): The 2x3 board configuration.

        Returns:
        int: Minimum number of moves to solve the puzzle, or -1 if unsolvable.
        """
        # Convert the board into a string
        start = ''.join(str(num) for row in board for num in row)
        goal = "123450"

        # Valid moves based on the position of '0'
        moves = {
            0: [1, 3],
            1: [0, 2, 4],
            2: [1, 5],
            3: [0, 4],
            4: [1, 3, 5],
            5: [2, 4],
        }

        # BFS setup
        queue = deque([(start, start.index('0'), 0)])  # (current state, index of 0, depth)
        visited = set()
        visited.add(start)

        while queue:
            state, zero_idx, steps = queue.popleft()

            # Check if we have reached the goal state
            if state == goal:
                return steps

            # Generate possible next states
            for move in moves[zero_idx]:
                # Swap '0' with the adjacent position
                new_state = list(state)
                new_state[zero_idx], new_state[move] = new_state[move], new_state[zero_idx]
                new_state_str = ''.join(new_state)

                # Add the new state to the queue if not visited
                if new_state_str not in visited:
                    visited.add(new_state_str)
                    queue.append((new_state_str, move, steps + 1))

        # If the goal state is not reachable
        return -1
