# Q977. Squares of a Sorted Array
"""
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
"""

from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        nums_squared = [x**2 for x in nums]
        nums_squared.sort()

        return nums_squared

# Time complexity: O(nlogn)
# Space complexity: O(n)

# Test
nums = [-0]
s = Solution()
print(s.sortedSquares(nums)) # [0,1,9,16,100]