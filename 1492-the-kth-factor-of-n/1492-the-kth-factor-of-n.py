import math

class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        """
        Finds the k-th factor of the integer n using an optimized approach.

        Parameters:
        n (int): The number whose factors are being considered.
        k (int): The k-th factor to be found.

        Returns:
        int: The k-th factor of n if it exists, otherwise -1.
        """
        factors = []  # List to store factors of n
        
        # Iterate through numbers up to sqrt(n)
        for i in range(1, int(math.sqrt(n)) + 1):
            print(i, end = " ")
            if n % i == 0:  # If i is a divisor of n
                factors.append(i)  # Add the divisor to the list
                if i != n // i:  # Avoid adding the square root twice
                    factors.append(n // i)
        
        # Sort the factors list to find the k-th smallest factor
        print(factors)
        factors.sort()
        
        # If k is valid, return the k-th factor; otherwise, return -1
        return factors[k - 1] if k <= len(factors) else -1

