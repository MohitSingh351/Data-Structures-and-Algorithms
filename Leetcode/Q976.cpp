// Largest Perimeter Triangle
/*
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

Example 1:
Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // length of nums
        int length = nums.size();
        // sort the array
        sort(nums.begin(), nums.end());
        
        for (int i = length - 1; i >= 2; i--) {
            int l3 = nums[i];
            int l2 = nums[i-1];
            int l1 = nums[i-2];
            if (l1 + l2 > l3) {
                return l1 + l2 + l3;
            }
        }

        return 0;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,1,10};
    cout << s.largestPerimeter(nums) << endl;
    return 0;
}