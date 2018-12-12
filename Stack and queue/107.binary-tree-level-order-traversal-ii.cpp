/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (44.59%)
 * Total Accepted:    195.7K
 * Total Submissions: 438.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> s;
        if(root==NULL)
            return vector<vector<int>>();
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level = q.front().second;
            q.pop();

            if(level==s.size())
                s.push(vector<int>());

            vector<int> tmp = s.top();s.pop();
            tmp.push_back(node->val);
            s.push(tmp);
            if(node->left)
                q.push(make_pair(node->left,level+1));
            if(node->right)
                q.push(make_pair(node->right,level+1));
        }
        vector<vector<int>> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};
