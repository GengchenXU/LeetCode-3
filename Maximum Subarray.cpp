//
// Created by admin on 2018/10/19.
//
#include <stdio.h>
#include <math.h>
int maxSubArray(int* nums, int numsSize) {
    int dp[numsSize];
    *dp = *nums;
    int max = *nums;
    for (int i = 0; i < numsSize - 1; ++i) {
        dp[i + 1] = nums[i + 1] + (dp[i] > 0 ? dp[i] : 0);
        max = max > dp[i + 1] ? max : dp[i + 1];
    }
    return max;
}

int main(){
    int a[] = {2, 6, -3,-1,2,9 -3, };
    printf("%d ", maxSubArray(a, 6));

}