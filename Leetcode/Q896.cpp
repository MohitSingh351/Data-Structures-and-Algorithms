/*896. Monotonic Array
Easy
Topics
Companies
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

 

Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int length = nums.size();
        int increasing = 1;
        int decreasing = 1;

        if (length == 0 || length == 1) {
            return true;
        }

        for (int i=0; i<length-1; i++) {
            if (nums[i] <= nums[i+1]) {
                increasing++;
            }
            if (nums[i] >= nums[i+1]) {
                decreasing++;
            }
        }
        
        // if (increasing == decreasing) {
        //     return true;
        // }
        if (increasing == length || decreasing == length) {
            return true;
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2};
    cout << s.isMonotonic(nums);

    return 0;
}