from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()  # Sorting the list
        length = len(nums)
        result = []

        for i in range(length - 2):
            # Skip duplicate values for the first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            j, k = i + 1, length - 1
            
            while j < k:
                total = nums[i] + nums[j] + nums[k]
                
                if total == 0:
                    result.append([nums[i], nums[j], nums[k]])
                    # Skip duplicate values for the second element
                    while j < k and nums[j] == nums[j + 1]:
                        j += 1
                    # Skip duplicate values for the third element
                    while j < k and nums[k] == nums[k - 1]:
                        k -= 1
                    j += 1
                    k -= 1
                elif total < 0:
                    j += 1
                else:
                    k -= 1

        return result

nums = [-2,0,0,2,2]
nums1 = [-1,-1,0,1,1]
sol = Solution()
print(sol.threeSum(nums1))