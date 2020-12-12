/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<queue>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<TreeNode*> Qnode;
        Qnode.push(root);
        int depth = 1;

        while (!Qnode.empty())
        {
            int qsize = Qnode.size();
            while (qsize--)
            {
                TreeNode* cur = Qnode.front();
                Qnode.pop();

                if(cur->left == NULL && cur->right == NULL)
                    return depth;

                if(cur->left != NULL)
                    Qnode.push(cur->left);
                if(cur->right != NULL)
                    Qnode.push(cur->right);
            }
            depth++;
        }

        return depth;
    }
};
// @lc code=end

