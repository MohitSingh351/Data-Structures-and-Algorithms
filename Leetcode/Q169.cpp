// Q169. Majprity Element
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        // Initialize the map with 0
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }
        for(const auto& pair : map) {
            if(pair.second > nums.size() /2) {
                return pair.first;
            }
        }
        return -1;
    }
};

// Moore's Voting Algorith, (best solution)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element;
        for (int i=0; i<nums.size(); i++) {
            if (count == 0) {
                count = 1;
                element = nums[i];
            } else if (element == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        int count1 = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == element) {
                count1++;
            }
        }
        if(count1 > nums.size() / 2) {
            return element;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,3,2,2};
    cout << sol.majorityElement(nums) << endl;
    return 0;
}