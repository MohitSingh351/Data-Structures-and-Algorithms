# Q 118. Pascal's Triangle
"""
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
"""
from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        main = []
        for i in range(numRows):
            row = []
            for j in range(i + 1):  # j ranges from 0 to i (inclusive)
                if j == 0 or j == i:
                    # First or last element in the row is always 1
                    row.append(1)
                else:
                    # Sum of the two elements above in the previous row
                    value = main[i-1][j-1] + main[i-1][j]
                    row.append(value)
            
            main.append(row)

        return main

sol = Solution()
result = sol.generate(5)
print(result)
