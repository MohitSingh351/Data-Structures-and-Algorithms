"""
1002. Find Common Characters
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
"""

from typing import List

class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        dict1 = {}
        for i in words[0]:
            if i in dict1:
                dict1[i] += 1
            else:
                dict1[i] = 1
        for i in range(1, (len(words))):
            dict2 = {}
            for j in words[i]:
                if j in dict2:
                    dict2[j] += 1
                else:
                    dict2[j] = 1
            for char in dict1:
                if char in dict2:
                    dict1[char] = min(dict1[char], dict2[char])
                else:
                    dict1[char] = 0
        result = []
        for char in dict1:
            if dict1[char] > 0:
                result += [char]*dict1[char]

        return result
    
words = ["abc", "", "cba"]
words1 = ["bella", "label", "roller"]
sol = Solution()
print(sol.commonChars(words))
