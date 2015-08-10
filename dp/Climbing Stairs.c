#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
    int *dp = malloc(3*sizeof(int));
    dp[0]=dp[1]=1;
    int i;
    for(i = 2; i<=n;i++) dp[i%3] = dp[(i+1)%3] +dp[(i+2)%3];
    return dp[n%3];
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
