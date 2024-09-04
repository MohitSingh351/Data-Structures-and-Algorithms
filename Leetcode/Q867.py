# Q867. Transpose matrix
"""
Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
"""

from typing import List

class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        transpose = [[0] * len(matrix) for _ in range(len(matrix[0]))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                transpose[j][i] = matrix[i][j]
                
        return transpose

matrix = [[1,2,3],[4,5,6],[7,8,9]]
sol = Solution()
print(sol.transpose(matrix))
