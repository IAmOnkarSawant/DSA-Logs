#include <stdio.h>
#include <string.h>

int isPowerOfTwo(char* s) {
    int countOnes = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            countOnes++;
        } else if (s[i] != '0') {
            return 0; 
        }
    }
    
    return countOnes == 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        char s[1001];  // Assuming maximum binary string length of 1000
        scanf("%s", s);
        
        if (isPowerOfTwo(s)) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
    
    return 0;
}
