/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root==NULL){
        return false;
    } else if(root->left==NULL && root->right==NULL){
        return root->val==targetSum;
    }
    int diff=targetSum-root->val;
    return hasPathSum(root->left,diff) || hasPathSum(root->right,diff);
}
