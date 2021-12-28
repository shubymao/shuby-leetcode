#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        unordered_map<int,int> mp;
        int len = nums.size(), res = 0;
        for(int c = 2 ; c <= len - 2 ; c++){
            for(int a = 0 ; a < c - 1 ; a++){
                mp[nums[a]+nums[c-1]]++;
            }
            for(int d = c+1 ; d < len ; d++){
                res+=mp[nums[d]-nums[c]];
            }
        }
        return res;
    }
};