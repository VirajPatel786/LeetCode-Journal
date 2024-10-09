#include <stdlib.h>

/**
 * @brief Comparison function for qsort to sort an array of integers.
 *
 * @param a (const void*): Pointer to the first element for comparison.
 * @param b (const void*): Pointer to the second element for comparison.
 *
 * @return (int): Returns a negative value if the first integer is less than the second,
 *                a positive value if the first integer is greater, and 0 if they are equal.
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * @brief Divides players into pairs such that each pair has an equal sum of skills and calculates the sum
 *        of the product of the skills in each pair.
 *
 * @param skills (int*): Array of integers representing the skill levels of the players.
 * @param skillSize (int): The number of players, i.e., the size of the skills array.
 *
 * @return (long long): Returns the sum of the product of the skills in each pair, or -1 if the division is not possible.
 */
long long dividePlayers(int* skills, int skillSize) {
    // Edge case: if there are exactly 2 players, return the product of their skills.
    if (skillSize == 2) {
        return (skills[0] * skills[1]);
    }

    // Calculate the total sum of all players' skills.
    int total_skill_sum = 0;
    for (int i = 0; i < skillSize; i++) {
        total_skill_sum += skills[i];
    }

    // Calculate the number of pairs
    int num_pairs = skillSize / 2;

    // If the total skill sum cannot be evenly divided into pairs, return -1.
    if ((total_skill_sum % num_pairs) != 0) {
        return -1;
    }

    // Sort the skill levels to facilitate pairing
    qsort(skills, skillSize, sizeof(int), compare);

    // The expected sum for each pair of players
    int expected_pair_sum = skills[0] + skills[skillSize - 1];

    // Initialize variables to store player skills and the total product sum
    int left_player_skill, right_player_skill;
    long long total_pair_product_sum = 0;

    // Form pairs from the sorted list
    for (int i = 0; i < num_pairs; i++) {
        // Take the i-th player from the left and the i-th player from the right
        left_player_skill = skills[i];
        right_player_skill = skills[skillSize - 1 - i];

        // If the sum of the pair does not match the expected pair sum, return -1.
        if ((left_player_skill + right_player_skill) != expected_pair_sum) {
            return -1;
        }

        // Add the product of the skills of the pair to the total product sum
        total_pair_product_sum += (long long)left_player_skill * right_player_skill;
    }

    // Return the total sum of the products of all pairs
    return total_pair_product_sum;
}
