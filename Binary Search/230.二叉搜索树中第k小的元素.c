/*
 * @lc app=leetcode.cn id=230 lang=c
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int res = 0, kth = 0;

void inOrder(struct TreeNode* root){
    if(root == NULL)
        return;

    inOrder(root->left);

    if(--kth == 0){
        res = root->val;
        return;
    }

    inOrder(root->right);
}

int kthSmallest(struct TreeNode* root, int k){
    kth = k;
    inOrder(root);

    return res;
}
// @lc code=end

