// Contains duplicate
/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <iostream>
// set
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int i;
        unordered_set<int> s;

        for(i=0; i<nums.size(); i++) {
            if(s.find(nums[i]) != s.end()) { // Checks if the current element (nums[i]) is already in the set s.
            // If found (find returns an iterator not equal to s.end()), it means there is a duplicate, and the function returns true.
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

int main() {

    vector<int> nums = {1,2,3,1};
    Solution s;
    cout << s.containsDuplicate(nums) << endl;

    return 0;
}