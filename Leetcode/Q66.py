"""
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.


Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
"""

from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        string1 = ""

        for i in digits:
            string1 += str(i)
        
        string1 = str(int(string1) + 1)
        digits = []
        for i in string1:
            digits.append(int(i))
        return digits
    
sol = Solution()
print(sol.plusOne([1,2,3]))
