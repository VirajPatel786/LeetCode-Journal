int bitLength(int num) {
    int length = 0;

    while(num > 0) {
        num >>= 1;
        length++;
    }

    return length;
}

int findComplement(int num) {
    long mask = ((long)1 << bitLength(num)) - 1;
    return (int)(mask ^ num);
}