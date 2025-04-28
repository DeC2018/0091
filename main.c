#include <stdio.h>
#include <string.h>
#include <stdint.h>

int numDecodings(char* s) {
    if(strlen(s) == 0 || s[0] == '0'){
        return 0;
    }

    uint32_t dp[strlen(s) + 1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= strlen(s); i++){
        dp[i] = 0;
        int oneDigit = s[i - 1] - '0';
        int twoDigits = (s[i - 1] - '0') + (s[i - 2] - '0') * 10;

        if(oneDigit != 0) {
            dp[i] += dp[i - 1];
        }
        if(10 <= twoDigits && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return (int)dp[strlen(s)];
}

int main() {
    char s1[] = "12";
    printf("Input: s = \"%s\"\n", s1);
    printf("Output: %d\n", numDecodings(s1));
    
    char s2[] = "226";
    printf("Input: s = \"%s\"\n", s2);
    printf("Output: %d\n", numDecodings(s2));
    
    char s3[] = "06";
    printf("Input: s = \"%s\"\n", s3);
    printf("Output: %d\n", numDecodings(s3));
    
    return 0;
}
