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
    int kthSmallest(TreeNode* root, int k) {

       int count=0;

       //morris traversal for inorder

       TreeNode* curr=root;

       while(curr!=NULL){
         if(curr->left==NULL){
            //store the value
            count++;
            if(count==k){
                return curr->val;
                
            }

            curr=curr->right;
         }

         else{
            TreeNode* leftChild=curr->left;
            while(leftChild->right!=NULL){
                  leftChild=leftChild->right;
            }
            leftChild->right=curr;

            TreeNode* temp=curr;
            curr=curr->left;
            temp->left=NULL;

         }

       } 
       return -1;
    }
};