class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        """
        Check if array can be divided into pairs such that the sum of each pair is divisible by k.

        Parameters:
        arr (list[int]): The input array of integers.
        k (int): The divisor for divisibility check.

        Returns:
        bool: True if the array can be arranged, otherwise False.
        """
        # Create a list to store the frequency of remainders
        remainder_count = [0] * k
        
        # Count the frequency of each remainder
        for num in arr:
            remainder = num % k
            # Adjust remainder if it's negative
            if remainder < 0:
                remainder += k
            remainder_count[remainder] += 1
        
        # Check the condition for elements divisible by k (remainder == 0)
        if remainder_count[0] % 2 != 0:
            return False
        
        # Check pairs for other remainders
        for i in range(1, k // 2 + 1):
            if remainder_count[i] != remainder_count[k - i]:
                return False
        
        # Special case for even k (remainder == k // 2)
        if k % 2 == 0 and remainder_count[k // 2] % 2 != 0:
            return False
        
        return True
