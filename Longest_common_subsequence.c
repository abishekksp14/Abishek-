#include <stdio.h>
#include <string.h>

int LCS(char a[], char b[]) {
    int m = strlen(a);
    int n = strlen(b);
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
  
    return dp[m][n];
}



int main() {
    char a[] = "babbab";
    char b[] = "abaaba";

    int res = LCS(a, b);
    printf("The longest common subsequence length is %d\n", res);

    return 0;
}
