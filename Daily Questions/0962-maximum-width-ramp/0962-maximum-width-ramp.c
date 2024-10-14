/**
 * @brief Finds the maximum width ramp in the given array.
 *
 * A ramp is defined as a pair (i, j) where i < j and nums[i] <= nums[j]. This
 * function returns the maximum width (j - i) for any valid ramp.
 *
 * @param nums (int*): Array of integers where we need to find the ramp.
 * @param numsSize (int): The size of the nums array.
 *
 * @return (int): The maximum width of the ramp.
 */

int maxWidthRamp(int* nums, int numsSize) {
    // Initialize a stack array to store the indices of potential starting points of a ramp.
    int stack[numsSize];  // Holds the indices of nums in a decreasing sequence.
    int stack_length = 0; // Variable to track the length of the stack.

    // First pass: build a stack of indices where nums[i] are in a non-increasing order.
    for (int i = 0; i < numsSize; i++) {
        // If the stack is empty or the current number is smaller than the number at the
        // top of the stack, push the current index onto the stack.
        if (stack_length == 0 || nums[stack[stack_length - 1]] > nums[i]) {
            stack[stack_length++] = i;  // Push the current index onto the stack.
        }
    }

    // Initialize result to store the maximum width of the ramp.
    int result = 0;

    // Second pass: traverse the array in reverse to find the widest ramp.
    for (int i = numsSize - 1; i >= 0; i--) {
        // While the stack is not empty and nums[i] can form a valid ramp with the top of the stack.
        while (stack_length > 0 && nums[stack[stack_length - 1]] <= nums[i]) {
            // Calculate the width of the ramp and update the result if this ramp is wider.
            int width = i - stack[--stack_length];
            result = result > width ? result : width;  // Update the result with the maximum width.
        }

        // Early exit: if the stack is empty, no more ramps are possible.
        if (stack_length == 0) {
            break;
        }
    }

    // Return the maximum width of the ramp found.
    return result;
}
