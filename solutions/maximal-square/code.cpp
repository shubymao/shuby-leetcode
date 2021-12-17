#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int res = 0;
        vector<vector<int>> dp(2, vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            dp[1][0] = matrix[i][0] == '1' ? 1 : 0;
            res = max(res, dp[1][0]);
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] != '0')
                    dp[1][j] =
                        min(dp[0][j - 1], min(dp[0][j], dp[1][j - 1])) + 1;
                else
                    dp[1][j] = 0;
                res = max(res, dp[1][j]);
            }
            for (int k = 0; k < matrix[0].size(); k++) {
                dp[0][k] = dp[1][k];
            }
        }
        return res * res;
    }
};