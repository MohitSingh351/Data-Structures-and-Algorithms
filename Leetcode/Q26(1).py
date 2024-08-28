# Remove duplicates from sorted array
# Input: nums = [0,0,1,1,1,2,2,3,3,4]
# Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
# Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
# It does not matter what you leave beyond the returned k (hence they are underscores).
from typing import List

# Remove duplicates from sorted array
# Input: nums = [0,0,1,1,1,2,2,3,3,4]
# Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
# Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
# It does not matter what you leave beyond the returned k (hence they are underscores).
from typing import List

class Solution(object):
    def removeDuplicates(self, nums):
        if not nums:
            return 0
        
        # Pointer for the position of the last unique element
        unique_index = 0
        
        # Iterate over the array starting from the second element
        for current_index in range(1, len(nums)):
            # Check if the current element is different from the last unique element
            if nums[current_index] != nums[unique_index]:
                unique_index += 1
                nums[unique_index] = nums[current_index]
        
        # The number of unique elements is unique_index + 1
        return unique_index + 1

# Example usage
nums = [1, 1, 2]
solution = Solution()
num_unique_elements = solution.removeDuplicates(nums)

# Prepare the output
formatted_nums = nums[:num_unique_elements] + ['_'] * (len(nums) - num_unique_elements)
print("Output: {}, nums = {}".format(num_unique_elements, formatted_nums))
        