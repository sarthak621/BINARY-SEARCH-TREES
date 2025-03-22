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
class BSTIterator {
public:

    void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            if(reverse==false){
                root=root->left;
            }
            //for before
            else{
                root=root->right;
            }
        }
    }

    stack<TreeNode*>st;
    bool reverse=true;  ///for tracking the before elements i.e. first before in this is 7

    BSTIterator(TreeNode* root,bool isReverse) {
        reverse=isReverse;    
        pushAll(root);    
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();

        //for next
        if(!reverse){
            if(temp->right) pushAll(temp->right);
            // return temp->val;
        }

        //for before
        else{
            if(temp->left) pushAll(temp->left);
            // return temp->val;
        }
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
             if(!root) return false;
             BSTIterator l(root,false);
             BSTIterator r(root,true);

             int i=l.next();
             int j=r.next(); 

             while(i<j){
                if(i+j==k) return true;

                else if(i+j>k) j=r.next();
                else{
                    i=l.next();
                } 
             }
             return false;     
    }
};