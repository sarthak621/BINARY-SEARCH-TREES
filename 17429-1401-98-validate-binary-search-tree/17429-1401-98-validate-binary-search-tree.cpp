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
    

    bool checkValidBST(TreeNode* root,long long minVal, long long maxVal){
        if(root==NULL) return true;

        if(root->val>minVal && root->val<maxVal){
                return (checkValidBST(root->left,minVal,root->val) &&
               checkValidBST(root->right,root->val,maxVal)); 
        }
        else return false;

        

    }

    bool isValidBST(TreeNode* root) {
        return checkValidBST(root,LLONG_MIN,LLONG_MAX);
    }
};