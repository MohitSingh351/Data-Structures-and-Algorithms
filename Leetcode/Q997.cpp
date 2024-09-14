/*997. Find the Town Judge

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:
The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

Example 1:
Input: n = 2, trust = [[1,2]]
Output: 2

Example 2:
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1;

        int length = trust.size();

        // make array of people who trust others
        vector<int> trustOthers(n+1, 0);

        // make array of people who are trusted by others
        vector<int> trustedByOthers(n+1, 0);

        for (int i = 0; i < length; i++) {
            trustOthers[trust[i][0]]++;
            trustedByOthers[trust[i][1]]++;
        }

        int judge = -1;

    
        for (int i = 1; i <= n; i++) {
            if (trustOthers[i] == 0 && trustedByOthers[i] == n-1) {
                judge = i;
                break;
            }
        }
        return judge;
    }
};

int main() {
    Solution s;
    vector<vector<int>> trust = {{1,3}, {1,4}, {2,3}, {2,4}, {4,3}};
    cout << s.findJudge(4, trust);
    return 0;
}