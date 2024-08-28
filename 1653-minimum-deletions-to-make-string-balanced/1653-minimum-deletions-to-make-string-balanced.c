int minimumDeletions(char* s) {
    int ans = 0; 
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'b') {
            count++;
        }
        else if (count > 0) {
            ans++;
            count--;
        }
    }
    return ans;
}