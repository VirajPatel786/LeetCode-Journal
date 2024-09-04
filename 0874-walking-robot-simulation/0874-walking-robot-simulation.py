class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # Directions: north, east, south, west (in terms of (dx, dy) pairs)
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # north, east, south, west
        direction_idx = 0  # Starting direction is north (index 0)
        
        # Convert the obstacle list to a set of tuples for fast lookup
        obstacle_set = set(map(tuple, obstacles))
        
        # Starting coordinates of the robot
        x, y = 0, 0
        
        # To keep track of the maximum distance squared from the origin
        max_distance_sq = 0
        
        # Process each command
        for command in commands:
            if command == -2:  # Turn left 90 degrees
                direction_idx = (direction_idx - 1) % 4
            elif command == -1:  # Turn right 90 degrees
                direction_idx = (direction_idx + 1) % 4
            else:  # Move forward `command` steps
                for _ in range(command):
                    # Calculate the next position
                    next_x = x + directions[direction_idx][0]
                    next_y = y + directions[direction_idx][1]
                    
                    # If the next position is an obstacle, stop moving
                    if (next_x, next_y) in obstacle_set:
                        break
                    
                    # Otherwise, update the robot's position
                    x, y = next_x, next_y
                    
                    # Update the maximum distance squared from the origin
                    max_distance_sq = max(max_distance_sq, x * x + y * y)
        
        return max_distance_sq