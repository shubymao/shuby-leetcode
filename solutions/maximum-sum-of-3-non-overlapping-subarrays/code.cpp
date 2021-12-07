#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
            // best start index less/greater than i (inclusive)
            vector<int> bestLeftIndex(nums.size(), -1), bestRightIndex(nums.size(), -1);
            // sum of the segment [i, i + k - 1]
            vector<int> dp(nums.size(), INT_MIN);
            
            // Construct the dp array
            int sum = 0;
            for(int i = 0 ; i < nums.size() ; i++){
                sum += nums[i];
                if(i>=k)sum -= nums[i-k];
                if(i>=k-1)dp[i-k+1] = sum;
            }

            // Find the best left index for position i
            for(int i = k-1 ; i < nums.size() ; i++){
                int bestPrevLeft = i == k-1 ? i-k+1 : bestLeftIndex[i-1];
                bestLeftIndex[i] = dp[bestPrevLeft] >= dp[i-k+1] ? bestPrevLeft : i-k+1;
            }

            // Find the best right index for position i
            for(int i = nums.size() - k ; i >= 0 ; i--){
                int bestPrevRight = i == nums.size() - k ? i : bestRightIndex[i+1];
                bestRightIndex[i] = dp[bestPrevRight] > dp[i] ? bestPrevRight : i;
            }

            int best = INT_MIN;
            vector<int> res;
            // Iterate over all possible mid start position
            for(int i = k ; i < nums.size() - 2*k + 1; i++){
                int left = bestLeftIndex[i-1];
                int right = bestRightIndex[i+k];
                int sum = dp[i] + dp[left] + dp[right];
                // If the sum is greater than the best sum, update best position
                if(sum > best){
                    best = sum;
                    res = {left, i, right};
                }
                // else update only if equal total and lexigorically smaller
                else if(best == sum) {
                    vector<int> temp = {left, i, right};
                    if(lessThan(temp, res)){
                        best = sum;
                        res = {left, i, right};
                    }
                }
            }
            return res;
        }


        // Helper function to compare two vectors
        bool lessThan(vector<int> a, vector<int> b){
            if(a[0] < b[0])return true;
            else if (b[0] > a[0])return false;
            else {
                if(a[1] < b[1])return true;
                else if (b[1] > a[1])return false;
                else {
                    if(a[2] < b[2])return true;
                    else return false;
                }
            }
        }
};