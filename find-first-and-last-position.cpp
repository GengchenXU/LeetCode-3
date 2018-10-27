//
// Created by admin on 2018/10/27.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if (nums.empty())
            return res;
        return help(nums, target);
    }

    int binarySearch(vector<int> nums, int target, int left, int right){
        int mid = left + (right - left)/2;
        while (left <= right){
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = left + (right - left)/2;
        }
        return -1;
    }

    vector<int> help(vector<int> nums, int target){
        vector<int> res(2, -1);
        int left = 0, right = nums.size() - 1;
        int mid = binarySearch(nums, target, left, right);
        if (mid == -1)
            return res;

        int temp = mid;
        do{
            temp = binarySearch(nums, target, left, temp);
            if (res[0] != temp)
                res[0] = temp;
            else
                break;
        } while (true);

        temp = mid;
        do{
            temp = binarySearch(nums,target, temp, right);
            if (res[1] != temp)
                res[1] = temp;
            else
                break;
        } while (true);

        cout << res[0] << res[1];
        return res;
    }

    int binarySearchLeft(vector<int> nums, int target){
        int left = 0, right = nums.size() - 1;
        int mid;

        while (left != right){
            mid = left + (right - left)/2;
            if (nums[mid] >= target){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left] == target ? left : -1;
    }

    int binarySearchRight(vector<int> nums, int target){
        int left = 0, right = nums.size() - 1;
        int mid;

        while (left != right){
            mid = left + (right - left)/2;
            if (nums[mid] > target){
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }

};

int main(){
    Solution s;
    vector<int> a{5,5,5,5,5,7,8};
    vector<int> b{1,2,3,4,6,8,9};
    vector<int> c{2,5,5,5,5,5};
//    cout << s.binarySearchLeft(b, 6);
    cout << s.binarySearchRight(b, 3);
//    s.help(c, 5);
    return 0;
}