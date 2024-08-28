# Remove element
"""
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.

Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).

"""

from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0   # This will count the elements not equal to val
        length = len(nums)
        for i in range(length):
            if nums[i] != val:
                k += 1
        
        return k

sol = Solution()
nums = [3,2,2,3]
val = 2
result = sol.removeElement(nums, val)
print(f"{result}, {nums}")