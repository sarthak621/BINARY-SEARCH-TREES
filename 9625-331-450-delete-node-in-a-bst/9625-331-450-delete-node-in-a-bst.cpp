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
    TreeNode* lastNodeLeft(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
   
    TreeNode* helper(TreeNode* root, int key){
          
          //edge case
          if(root->left==NULL) return root->right;
          if(root->right==NULL) return root->left;

          //means root have now both left and right
          TreeNode* rightSide=root->right;
          TreeNode* lastNodeOfLeftSide= lastNodeLeft(root->left);

          lastNodeOfLeftSide->right=rightSide;
          return root->left;

    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(root->val==key){
            return helper(root,key); //helper func helps us to delete 
        }

        TreeNode* dummy= root;

        //search for that key
        while(root!=NULL){
            if(root->val>key){
                //key is present in the left
                if(root->left!=NULL && root->left->val==key){
                    root->left= helper(root->left,key);
                    break;
                }
                else{
                     root=root->left;
                }
            }
            else{
                //key is present in the right
                if(root->right!=NULL && root->right->val==key){
                    root->right= helper(root->right,key);
                    break;
                }
                else{
                     root=root->right;
                }
            }
        }
        return dummy;
    }
};