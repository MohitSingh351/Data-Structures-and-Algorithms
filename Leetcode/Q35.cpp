// Search insert position

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

// Using Linear Search
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            } else {
                if (nums[i] > target) {
                    return i;
                } else if (i == nums.size() - 1) {
                    return i+1;
                }
            }
        }
        return nums.size();
    }
};

// Using Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};



int main() {

    Solution sol;
    vector<int> nums1 = {1,3,5,6};
    int target1 = 5;
    cout << sol.searchInsert(nums1, target1) << endl;

    vector<int> nums2 = {1,3,5,6};
    int target2 = 2;
    cout << sol.searchInsert(nums2, target2) << endl;

    vector<int> nums3 = {1,3,5,6};
    int target3 = 7;
    cout << sol.searchInsert(nums3, target3) << endl;

    return 0;
}