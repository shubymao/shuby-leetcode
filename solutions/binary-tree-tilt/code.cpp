#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findTilt(TreeNode* root) {
        int res = 0;
        helper(root,res);
        return res;
    }
    
    int helper(TreeNode* root, int& tiltSum){
        if(root == nullptr)return 0;
        auto left = helper(root->left, tiltSum);
        auto right = helper(root->right, tiltSum);
        int sum = left + right + root->val;
        tiltSum += abs(left-right);
        return sum;
    }
};