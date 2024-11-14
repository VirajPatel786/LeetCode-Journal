#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Determines if products can be distributed without any store
 *        receiving more than max_products.
 *
 * @param quantities (int*): Array of quantities for each product type.
 * @param m (int): Length of the quantities array.
 * @param max_products (int): Maximum products allowed per store.
 * @param n (int): Total number of stores.
 *
 * @return (bool): True if distribution is possible under max_products, False otherwise.
 */
bool can_distribute(int *quantities, int m, int max_products, int n) {
    int stores_needed = 0;  // Initialize the number of stores required
    for (int i = 0; i < m; i++) {
        // Calculate stores needed for each product type if max_products is the limit per store
        stores_needed += (quantities[i] + max_products - 1) / max_products;
        // If stores needed exceed available stores, distribution is not feasible
        if (stores_needed > n) {
            return false;
        }
    }
    return true;  // Distribution is feasible with max_products as the limit per store
}

/**
 * @brief Finds the minimized maximum number of products any store can receive.
 *
 * @param n (int): Number of stores.
 * @param quantities (int*): Array of quantities of each product type.
 * @param m (int): Number of product types.
 *
 * @return (int): The minimum possible maximum number of products given to any store.
 */
int minimizedMaximum(int n, int* quantities, int m) {
    int left = 1;  // Minimum bound for binary search (at least one product per store)
    int right = 0; // Maximum bound, set to the largest quantity in quantities array

    // Find the maximum quantity in quantities for setting the upper bound
    for (int i = 0; i < m; i++) {
        if (quantities[i] > right) {
            right = quantities[i];
        }
    }

    // Binary search to find the minimized maximum distribution
    while (left < right) {
        int mid = (left + right) / 2;  // Calculate mid as current max_products limit
        // Check if distribution is feasible with mid as max products per store
        if (can_distribute(quantities, m, mid, n)) {
            right = mid;  // If feasible, try smaller max by moving right bound
        } else {
            left = mid + 1;  // If not feasible, increase left bound for larger max
        }
    }

    return left;  // The minimized maximum number of products any store receives
}
