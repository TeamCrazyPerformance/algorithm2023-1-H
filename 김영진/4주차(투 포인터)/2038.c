#include <stdio.h>

int dp[2000001] = { 0 };

int golomb(int n) {
    dp[1] = 1;
    int sum = dp[1];
    int i = 1;
    while (sum < n) {
        i++;
        dp[i] = 1 + dp[i - dp[dp[i - 1]]];
        sum += dp[i];
    }
    return i;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", golomb(n));
    return 0;
}
