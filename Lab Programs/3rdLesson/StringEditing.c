//
// Created by Dasaradha on 18/03/25.
//


#include <stdio.h>
#include <string.h>
int min(int i, int i1, int i2) {
    return (i < i1 && i < i2 ? i : ( i1 < i2 ? i1 : i2 ));
}
int main() {


    char s1[100];
    char s2[100];
    printf("Enter first string : ");
    scanf("%s",&s1);
    printf("Enter second string : ");
    scanf("%s",&s2);
    int length1 = (int) strlen(s1);
    int length2 = (int) strlen(s2);
    printf("%d %d ", length1, length2);
    int max = length1 > length2 ? length1 : length2;
    int dp[max+1][max+1];
    for (int i = 0; i <= max;i++) {
        dp[0][i] = i;
        dp[i][0] = i;
    }
    for (int i = 1;i <= max; i++) {
        for (int j = 1; j <= max; j++) {
            if (s2[i-1] == s1[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1;
            }
        }
    }
    printf("%d\n",dp[length1][length2]);
    for (int i = 0;i <= max; i++) {
        for (int j = 0; j <= max; j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
}