/**
 * @brief Calculates the minimum number of parentheses that need to be added to make the input string valid.
 *
 * This function iterates over the input string and keeps track of unmatched opening '(' and unmatched closing ')' parentheses.
 *
 * @param s (char*): Pointer to a null-terminated string of parentheses.
 *
 * @return (int): The minimum number of parentheses that need to be added to make the input string valid.
 */
int minAddToMakeValid(char* s) {
    int open_parentheses = 0;  /* Counter for unmatched opening '(' parentheses */
    int close_parentheses = 0; /* Counter for unmatched closing ')' parentheses */
    
    /* Iterate through the string until the null terminator is reached */
    for (; *s != '\0'; s++) {
        if (*s == '(') {
            /* Increment open_parentheses for each unmatched opening parenthesis */
            open_parentheses++;
        } else if (*s == ')' && open_parentheses > 0) {
            /* If there is an unmatched opening parenthesis, match it with the current closing parenthesis */
            open_parentheses--;
        } else {
            /* If no unmatched opening parenthesis, count this closing parenthesis as unmatched */
            close_parentheses++;
        }
    }

    /* The total number of additions needed is the sum of unmatched '(' and ')' */
    return open_parentheses + close_parentheses;
}
