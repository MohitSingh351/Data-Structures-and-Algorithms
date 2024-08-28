# Remove duplicates from sorted array
# Input: nums = [0,0,1,1,1,2,2,3,3,4]
# Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
# Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
# It does not matter what you leave beyond the returned k (hence they are underscores).
from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        i = 0
        j = 0
        k = 0
        unique = []

        for i in nums:
            if i not in unique:
                unique.append(i)
            else:
                k += 1 # no of duplicates

        for j in range(len(unique)):
            nums[j] = unique[j]
            # here value of j is 0, 1, 2, 3, 4

        # removing extra elements
        for i in range(k):
            nums.pop()
        no_unique_elements = len(unique)
        print(f"{no_unique_elements}, nums={nums}")
        return no_unique_elements
    
sol = Solution()
nums = [0,0,1,1,1,2,2,3,3,4]

# Output should be 2, [1, 2, _]
result = sol.removeDuplicates(nums)