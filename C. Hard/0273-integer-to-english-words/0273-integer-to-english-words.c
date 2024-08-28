char *belowTwenty[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                       "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

char *tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                "Seventy", "Eighty", "Ninety"};

char *thousands[] = {"", "Thousand", "Million", "Billion"};

char *str_concat(char *str1, char *str2) {
    if (strlen(str1) == 0) return strdup(str2); // Skip space if first string is empty
    if (strlen(str2) == 0) return strdup(str1); // Skip space if second string is empty

    char *result = malloc(strlen(str1) + strlen(str2) + 2); // 2 for space and null terminator
    strcpy(result, str1);
    strcat(result, " ");
    strcat(result, str2);
    return result;
}

char *helper(int num) {
    char *s = NULL;
    if (num < 20) {
        s = strdup(belowTwenty[num]);
    } else if (num < 100) {
        char *tens_part = strdup(tens[num / 10]);
        char *ones_part = strdup(belowTwenty[num % 10]);
        s = str_concat(tens_part, ones_part);
        free(tens_part);
        free(ones_part);
    } else if (num < 1000) {
        char *hundreds_part = str_concat(helper(num / 100), "Hundred");
        char *remainder_part = helper(num % 100);
        s = str_concat(hundreds_part, remainder_part);
        free(hundreds_part);
    } else if (num < 1000000) {
        char *thousands_part = str_concat(helper(num / 1000), "Thousand");
        char *remainder_part = helper(num % 1000);
        s = str_concat(thousands_part, remainder_part);
        free(thousands_part);
    } else if (num < 1000000000) {
        char *millions_part = str_concat(helper(num / 1000000), "Million");
        char *remainder_part = helper(num % 1000000);
        s = str_concat(millions_part, remainder_part);
        free(millions_part);
    } else {
        char *billions_part = str_concat(helper(num / 1000000000), "Billion");
        char *remainder_part = helper(num % 1000000000);
        s = str_concat(billions_part, remainder_part);
        free(billions_part);
    }

    return s;
}

char *numberToWords(int num) {
    if (num == 0) {
        return strdup("Zero");
    }

    char *result = helper(num);

    // Remove the trailing space, if any
    size_t len = strlen(result);
    if (len > 0 && result[len - 1] == ' ') {
        result[len - 1] = '\0';
    }

    return result;
}