/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (48.30%)
 * Total Accepted:    108.8K
 * Total Submissions: 225.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum =0;
        if(root==NULL ||(root->left==NULL && root->right==NULL)) return 0;
        if(root->left && root->left->left==NULL && root->left->right==NULL) sum += root->left->val;
        sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return sum;
    }
};
