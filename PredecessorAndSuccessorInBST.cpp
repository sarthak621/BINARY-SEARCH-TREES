/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
TreeNode* findingSucc(TreeNode *root, int key){
    TreeNode* successor=NULL;

    while(root!=NULL){
        if(root->data>key){
            successor=root;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    return successor;
}

TreeNode* findingPred(TreeNode *root, int key){
    TreeNode* predecessor=NULL;

    while(root!=NULL){
        if(root->data>=key){
            root=root->left;
        }
        else{
            predecessor=root;
            root=root->right;
        }
    }

    return predecessor;
}


pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.

    //finding the successor
    TreeNode* succ= findingSucc(root,key);

    //finding the predecessor
    TreeNode* pred= findingPred(root,key);

    return {pred ? pred->data : -1, succ ? succ->data : -1};
}
