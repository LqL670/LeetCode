/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (44.10%)
 * Total Accepted:    197.9K
 * Total Submissions: 448.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> res;
       if(root==NULL) return res;
       if(root->left==NULL && root->right==NULL){
           res.push_back(to_string(root->val));
           return res;
       }
       vector<string> lefts = binaryTreePaths(root->left);
       for(auto &i:lefts)
           res.push_back(to_string(root->val) + "->" + i);

       vector<string> rights = binaryTreePaths(root->right);
       for(auto &i:rights)
           res.push_back(to_string(root->val)+"->"+i);

       return res;
    }
};
