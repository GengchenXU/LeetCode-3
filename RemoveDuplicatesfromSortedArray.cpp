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

int main(){
    int arr[] = {-50,-50,-49,-49,-48,-48,-48,-47,-47,-47,-47,-47,-46,-45,-45,-45,-44,-43,-43,-42,-41,-41,-41,-40,-39,-38,-37,-37,-37,-35,-34,-34,-33,-33,-32,-31,-30,-29,-29,-28,-28,-28,-28,-26,-26,-25,-24,-24,-23,-22,-22,-21,-21,-20,-20,-19,-19,-18,-17,-17,-17,-17,-16,-16,-15,-14,-13,-13,-13,-12,-12,-12,-11,-11,-9,-8,-8,-7,-6,-6,-6,-6,-5,-5,-5,-5,-5,-4,-3,-1,-1,-1,-1,-1,0,1,1,2,3,3,3,4,5,5,5,5,6,7,7,8,8,8,8,8,8,9,9,10,10,10,10,11,11,12,12,12,12,12,14,15,15,16,16,17,18,18,19,19,19,20,20,21,21,22,23,23,24,24,25,25,25,26,26,28,30,30,30,31,31,33,33,33,34,34,34,34,34,37,38,38,39,40,40,40,41,41,41,41,41,41,41,43,43,44,44,45,46,46,46,46,48,48,49,50};
    int size = removeDuplicates(arr, 19);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
}