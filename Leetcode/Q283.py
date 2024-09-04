# 282. Move Zeroes
"""
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
"""

from typing import List
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        length = len(nums)
        test = [num for num in nums if num != 0]
        zeroes = [0] * (length - len(test))
        nums[:] = test + zeroes
        print(nums)

nums = [0,1,0,3,12]
sol = Solution()
sol.moveZeroes(nums)