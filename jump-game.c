//
// Created by admin on 2018/10/21.
//

#include <stdio.h>
#include <stdbool.h>
#include <intrin.h>

bool twoCompare(int *start, int *former, int *latter, int step){
    if (former == start){
//        printf("%d\n", step);
        return *former >= latter - former;
    }
    if (*former < step){
        return twoCompare(start, former - 1, latter, step + 1);
    } else {
        return twoCompare(start, former - 1, former, 1);
    }
}

bool canJump(int* nums, int numsSize) {
    if (numsSize == 1)
        return true;
    return twoCompare(nums, nums + numsSize - 2, nums + numsSize - 1, 1);
}

int main(){
    int a[] = {2,3,1,1,4};
    int b[] = {3,2,1,0,4};
    printf("%d\n", canJump(b, 5));
    return 0;
}