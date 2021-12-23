#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCnt;
        prefixSumCnt[0] = 1;
        int res = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int dif = sum - k;
            if (prefixSumCnt.count(dif) > 0) {
                res += prefixSumCnt[dif];
            }
            prefixSumCnt[sum]++;
        }
        return res;
    }
};