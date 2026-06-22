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

class Solution {
public:
    bool isSame(TreeNode* root, TreeNode* subRoot){
        
        if(root==NULL && subRoot!=NULL || root!=NULL && subRoot==NULL){
            return false;
        }
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(root->val != subRoot->val){
            return false;
        }

        bool lh = isSame(root->left, subRoot->left);
        if(lh==false){
            return false;
        }
        bool rh = isSame(root->right, subRoot->right);

        return lh && rh;
    }

    bool func(TreeNode* root, TreeNode* subRoot){
        if(root==NULL){
            return false;
        }
        if(root->val == subRoot->val && isSame(root, subRoot)){
            return true;
        }
        bool lh = func(root->left, subRoot);
        bool rh = func(root->right, subRoot);

        return lh||rh;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return func(root, subRoot);
    }
};
