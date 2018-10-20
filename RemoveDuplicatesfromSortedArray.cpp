//
// Created by admin on 2018/10/19.
//
#include <stdio.h>

int removeDuplicates2(int* nums, int numsSize) {
    if (numsSize <= 0){
        return 0;
    }

    for (int i = 0; i < numsSize - 1; i++){
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] == nums[j]){
                nums[j] = nums[numsSize - 1];
                printf("put %d to last one, numSize = %d now\n", nums[j], numsSize);
                j--;
                numsSize--;
            } else if (nums[i] < nums[j]){
                continue;
            } else {
                
            }
        }//for
    }//for
    return numsSize;
}

int removeDuplicates1(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < numsSize - 1; i++) {
            if (nums[i + 1] < nums[i]){ //bubble
                int temp = nums[i + 1];
                nums[i + 1] = nums[i];
                nums[i] = temp;
                printf("swap %d and %d \n", nums[i], nums[i+1]);
                flag = true;
            } else if (nums[i] == nums[i + 1]){
                nums[i + 1] = nums[numsSize - 1];
                numsSize--;
                i--;
                printf("put %d to last one, numSize = %d now\n", nums[i+1], numsSize);
            }
        }//for
    }
    return numsSize;
}

int removeDuplicates3(int* nums, int numsSize){
    int count = 0;
    for (int i = 0; i < numsSize - count; ++i) {
        if (nums[i] == nums[1 + count + i]) {
            count++;
            nums[i] = nums[i + count];
        }
    }
    return numsSize - count;
}

int removeDuplicates(int* nums, int numsSize){
    int count = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == nums[i - 1]){
            count++;
        } else {
            nums[i - count] = nums[i];
        }
    }
    return numsSize - count;
}
