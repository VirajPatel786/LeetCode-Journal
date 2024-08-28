bool lemonadeChange(int* bills, int billsSize) {
    int fiveBillsCount = 0, tenBillsCount = 0;
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            fiveBillsCount++;
        }
        else if (bills[i] == 10) {
            tenBillsCount++;
            fiveBillsCount--;
        }
        else {
            if (tenBillsCount > 0) {
                tenBillsCount--;
                fiveBillsCount--;
            }
            else {
                fiveBillsCount -= 3;
            }
        }
        if (fiveBillsCount < 0) {
            return false;
        }
    }
    return true;
}