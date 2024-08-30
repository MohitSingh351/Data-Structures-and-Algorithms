// Q118. Pascal's triangle
/*
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
*/

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> main;
        for(int i=0; i<numRows; i++) {
            vector<int> temp;
            for(int j=0; j<=i;j++) {
                if (i==j || j==0) {
                    temp.push_back(1);
                } else {
                    temp.push_back(main[i-1][j-1] + main[i-1][j]);
                }
            }
            main.push_back(temp);
        }
        return main;
    }
};


int main() {

    Solution s;
    vector<vector<int>> result = s.generate(5);
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}