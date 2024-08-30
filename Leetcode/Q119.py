"""
Pascal's Triangle II

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
"""


from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        main = []
        for i in range(rowIndex+1):
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
        return main[rowIndex]

sol = Solution()
result = sol.getRow(1)
print(result)