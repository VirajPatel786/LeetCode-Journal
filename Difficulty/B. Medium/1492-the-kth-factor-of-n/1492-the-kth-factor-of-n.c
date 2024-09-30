#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Comparator function for qsort.
 *
 * This function compares two integers and is used by qsort to sort the factors array.
 *
 * @param a (const void*): Pointer to the first element to compare.
 * @param b (const void*): Pointer to the second element to compare.
 *
 * @return (int): -1 if *a < *b, 1 if *a > *b, 0 if *a == *b.
 */
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * @brief Finds the k-th factor of a number n.
 *
 * This function finds the k-th factor of a number n using an optimized approach
 * by iterating only up to the square root of n. If k factors exist, it returns the k-th
 * smallest factor; otherwise, it returns -1.
 *
 * @param n (int): The number whose factors are being considered.
 * @param k (int): The k-th factor to find.
 *
 * @return (int): The k-th factor of n if it exists, otherwise -1.
 */
int kthFactor(int n, int k) {
    int factors[1000]; /* Array to store the factors of n */
    int count = 0;     /* Counter for the number of factors found */
    
    /* Iterate through numbers up to sqrt(n) */
    for (int i = 1; i <= (int)sqrt(n); ++i) {
        if (n % i == 0) {
            factors[count++] = i;   /* Add divisor i */
            if (i != n / i) {
                factors[count++] = n / i;  /* Add corresponding divisor n / i */
            }
        }
    }
    
    /* Sort the factors array using qsort */
    qsort(factors, count, sizeof(int), compare);
    
    /* Return the k-th factor if it exists, otherwise -1 */
    return (k <= count) ? factors[k - 1] : -1;
}