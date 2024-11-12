#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Determines if the array can be made strictly increasing by subtracting
 * prime numbers from each element.
 *
 * @param nums (int*): Pointer to the array of integers.
 * @param numsSize (int): The size of the array.
 *
 * @return (bool): Returns true if the array can be made strictly increasing by
 *                 subtracting prime numbers; otherwise, returns false.
 */
bool primeSubOperation(int* nums, int numsSize) {
    int i, j;
    
    // Find the maximum element in the array
    int max_value = nums[0];
    for (i = 1; i < numsSize; ++i) {
        if (nums[i] > max_value) {
            max_value = nums[i];
        }
    }
    
    // Allocate memory for the sieve array to mark prime numbers
    bool* is_prime = (bool*)malloc((max_value + 1) * sizeof(bool));
    if (is_prime == NULL) {
        return false;  // Return false if memory allocation fails
    }
    
    // Initialize all elements in the sieve array to true (assuming they are prime)
    for (i = 2; i <= max_value; ++i) {
        is_prime[i] = true;
    }
    is_prime[1] = false;  // Set 1 as not prime, as per convention
    
    // Use the Sieve of Eratosthenes to mark non-prime numbers in the array
    for (i = 2; i <= (int)sqrt(max_value); ++i) {
        if (is_prime[i]) {  // If 'i' is prime
            for (j = i * i; j <= max_value; j += i) {
                is_prime[j] = false;  // Mark multiples of 'i' as non-prime
            }
        }
    }

    // Start with a required_value of 1, representing the minimal target value for a strictly increasing sequence
    int required_value = 1;
    
    // Traverse the array to verify if we can achieve a strictly increasing sequence
    for (i = 0; i < numsSize; ++i) {
        int difference = nums[i] - required_value;  // Calculate difference with required value

        // Check if the current number is already smaller than required_value
        if (difference < 0) {
            free(is_prime);  // Free allocated memory for sieve array
            return false;     // Return false as we can't achieve a strictly increasing array
        }

        // If difference is zero or prime, move to the next element
        if (difference == 0 || is_prime[difference]) {
            required_value++;  // Increment required_value for the next element in sequence
        } else {
            // If difference is not prime, increment required_value and recheck the current element
            required_value++;
            i--;  // Decrement i to re-evaluate current element with new required_value
        }
    }
    
    // Free allocated memory for the sieve array before returning
    free(is_prime);
    return true;  // Return true if all elements satisfy the strictly increasing condition
}
