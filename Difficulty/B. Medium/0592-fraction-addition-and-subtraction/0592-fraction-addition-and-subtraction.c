int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* fractionAddition(char* expression) {
    int numerator = 0, denominator = 1;
    int num = 0, denom = 0;
    int sign = 1;  // To handle signs of fractions

    for (int i = 0; i < strlen(expression); i++) {
        // Handle signs
        if (expression[i] == '-' || expression[i] == '+') {
            sign = (expression[i] == '-') ? -1 : 1;
            i++;  // Move to the next character
        }

        // Read the numerator
        num = 0;
        while (isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');
            i++;
        }
        num *= sign;  // Apply sign to the numerator

        i++;  // Skip the '/'

        // Read the denominator
        denom = 0;
        while (isdigit(expression[i])) {
            denom = denom * 10 + (expression[i] - '0');
            i++;
        }

        // Calculate the new numerator and denominator
        numerator = numerator * denom + num * denominator;
        denominator *= denom;

        // Simplify the fraction using GCD
        int common_divisor = gcd(abs(numerator), denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;

        i--;  // Adjust the loop index since it will be incremented at the start of the loop
    }

    // Make sure the denominator is positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    // Allocate memory for the result string
    char* result = (char*)malloc(32 * sizeof(char));
    snprintf(result, 32, "%d/%d", numerator, denominator);

    return result;    
}