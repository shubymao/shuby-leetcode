#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmp;
        for (int i = 0; i < nums.size(); i++) {
            if (hmp.find(target - nums[i]) != hmp.end()) {
                return {hmp[target - nums[i]], i};
            }
            hmp[nums[i]] = i;
        }
        return {-1, -1};
    }
};