class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // if(root == NULL){
        //     return NULL;
        // }
        // if(root->val == val){
        //     return root;
        // }

        // if(root->val > val){
        //     return searchBST(root->left,val);
        // }
        // else{
        //     return searchBST(root->right,val);
        // }

        while(root != NULL && root->val != val){
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};
