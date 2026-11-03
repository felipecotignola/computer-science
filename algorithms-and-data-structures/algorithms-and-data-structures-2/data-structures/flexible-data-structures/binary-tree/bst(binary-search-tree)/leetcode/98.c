/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBst(struct TreeNode* root,long long min,long long max){
    if(root==NULL){
        return true;
    }
    if(root->val<=min || root->val>=max){
        return false;
    }
    return isBst(root->left,min,root->val) && isBst(root->right,root->val,max);
}
bool isValidBST(struct TreeNode* root) {
    if(root==NULL){
        return true;
    }
    long long min = LLONG_MIN;
    long long max = LLONG_MAX;
    return isBst(root->left,min,root->val) && isBst(root->right,root->val,max);
}
