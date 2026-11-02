/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode* left,struct TreeNode* right){
    if(left==NULL && right==NULL){return true;}
    if(left==NULL || right==NULL){return false;}
    if(left->val!=right->val){return false;}
    return isMirror(left->left,right->right) && isMirror(left->right,right->left);
}
bool isSymmetric(struct TreeNode* root) {
        if(root==NULL){
            return true;
        }
        struct TreeNode* left=root->left;
        struct TreeNode* right=root->right;
        return isMirror(left,right);    
}

