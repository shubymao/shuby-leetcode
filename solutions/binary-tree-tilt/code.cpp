#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int findTilt(TreeNode *root) {
        int res = 0;
        helper(root, res);
        return res;
    }

    int helper(TreeNode *root, int &tiltSum) {
        if (root == nullptr) return 0;
        auto left = helper(root->left, tiltSum);
        auto right = helper(root->right, tiltSum);
        int sum = left + right + root->val;
        tiltSum += abs(left - right);
        return sum;
    }
};