/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** str_array = malloc(n * sizeof(char*));
    if (str_array == NULL) {
        perror("Failed To Alloacte Memory For String Array");
        return NULL;
    }

    for(int i=1; i<=n; i++) {
        str_array[i-1] = malloc(10 * sizeof(char));
        str_array[i-1][0] = '\0';
        if (str_array[i-1] == NULL) {
            perror("Failed To Allocate Memory For String");
            return NULL;
        }

        if ((i%3) == 0) {
            strcat(str_array[i-1], "Fizz");
        }
        if ((i%5) == 0) {
            strcat(str_array[i-1], "Buzz");
        }
        if (str_array[i-1][0] == '\0') {
            sprintf(str_array[i-1], "%d", i); 
        }
    }
    return str_array;
}