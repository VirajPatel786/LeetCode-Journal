int minAddToMakeValid(char* s) {
    int open_parentheses = 0, close_parentheses = 0;
    for (; *s; s++) {
        if (*s == '(') {
            open_parentheses++;
        }
        else if (*s == ')' && open_parentheses > 0) {
            open_parentheses--;
        }
        else {
            close_parentheses++;
        }
    }
    return open_parentheses + close_parentheses;
}