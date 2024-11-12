class Solution:
    def primeSubOperation(self, nums: list[int]) -> bool:
        """
        Determines if it is possible to make the input list strictly increasing by
        subtracting prime numbers from each element.

        Parameters:
        nums (list[int]): A list of integers to be checked.

        Returns:
        bool: True if the list can be made strictly increasing by subtracting prime numbers;
              False otherwise.
        """
        
        # Find the maximum element in the input list
        max_value = max(nums)
        
        # Initialize sieve of Eratosthenes array to mark prime numbers up to max_value
        is_prime = [True] * (max_value + 1)
        is_prime[1] = False  # 1 is not considered a prime number
        
        # Use the Sieve of Eratosthenes to mark non-prime numbers
        for num in range(2, int((max_value + 1) ** 0.5) + 1):
            if is_prime[num]:
                for multiple in range(num * num, max_value + 1, num):
                    is_prime[multiple] = False

        # Attempt to make the array strictly increasing by subtracting prime numbers
        required_value = 1  # Initial value that nums[i] should exceed after modification
        
        # Traverse the nums array to check if we can achieve a strictly increasing sequence
        idx = 0  # Index for traversing the nums list
        while idx < len(nums):
            difference = nums[idx] - required_value  # Calculate difference with the required value
            
            # If the current element is already less than the required value, return False
            if difference < 0:
                return False
            
            # Move to the next element if the difference is either a prime number or zero
            if is_prime[difference] or difference == 0:
                idx += 1  # Advance to the next element
                required_value += 1  # Increment the required value to maintain strict increase
            else:
                # Increase the required value if the difference is not a prime
                required_value += 1
                
        return True
