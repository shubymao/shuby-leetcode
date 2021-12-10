#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = (int)1e9 + 7;
    int numTilings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2,0));
        // dp[i][0] means number of combination to fill ith col flat
        // dp[i][1] means number of combination to fill to i-1 th col
        // and 1 tile bump on top or bottom side
        dp[0][0] = 1;
        dp[1][0] = 1;
        for(int i = 1 ; i < n ; i++){
            
            // 1 tile ago flat, two tile ago flat, one tile ago bump
            // e.g * means exisiting tile -- means new tile
            // *-   or  *--  or **-
            // *-       *--     *--
            dp[i+1][0] = (dp[i+1][0] + dp[i][0]) % mod;
            dp[i+1][0] = (dp[i+1][0] + dp[i-1][0]) % mod;
            dp[i+1][0] = (dp[i+1][0] + dp[i][1]) % mod;
            
            // add 2 tile ago flat count as well 1 tile ago bump
            // e.g * means exisiting tile - means new tile
            // *--    or    *--
            // *-           ** 
            dp[i+1][1] = (dp[i-1][0] * 2) % mod;
            dp[i+1][1] = (dp[i+1][1] + dp[i][1]) % mod;
        }
        return dp[n][0];
    }
};