class Solution:
    def fractionAddition(self, expression: str) -> str:
        # Parse the input string
        fractions = re.findall(r'[+-]?\d+/\d+', expression)
        
        # Initialize numerator and denominator for the result
        numerator, denominator = 0, 1
        
        for frac in fractions:
            # Extract numerator and denominator from the fraction
            num, denom = map(int, frac.split('/'))
            
            # Calculate new numerator and denominator using common denominator
            numerator = numerator * denom + num * denominator
            denominator *= denom
            
            # Simplify the fraction
            common_divisor = gcd(abs(numerator), denominator)
            numerator //= common_divisor
            denominator //= common_divisor
        
        # Ensure the denominator is positive
        if denominator < 0:
            numerator = -numerator
            denominator = -denominator
        
        return f"{numerator}/{denominator}"
        