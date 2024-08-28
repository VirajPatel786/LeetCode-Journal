bool canConstruct(char* ransomNote, char* magazine) {
    int mag_count[256] = {0};   // Assuming ASCII Characters

    for(int i = 0; magazine[i] != '\0'; i++) {
        mag_count[(unsigned int)magazine[i]]++;
    }

    for(int i = 0; ransomNote[i] != '\0'; i++) {
        if (--mag_count[(unsigned int)ransomNote[i]] < 0) {
            return false;
        }
    }
    return true;
}