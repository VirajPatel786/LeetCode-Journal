// Comparison function
int compare(const void* a, const void* b) {
   return (*(int*)b - *(int*)a);
}

int minimumPushes(char* word) {
    int key_list_count[5] = {0, 8, 8, 8, 3};
    int freq[27] = {0};
    for(int i = 0; word[i] != '\0'; i++) {
        freq[(unsigned int)word[i] - 'a']++;
    }
    qsort(freq, 27, sizeof(int), compare);
    int cost = 0;
    for(int i = 0; i <= 26; i++){
        cost += freq[i] * (1 + (i / 8));
    }
    return cost;
}