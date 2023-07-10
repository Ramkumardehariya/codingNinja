class Solution {
public:
    // TreeNode* prev = NULL;
    // void solve(TreeNode* root){
    //     if(root == NULL){
    //         return;
    //     }

    //     solve(root->right);
    //     solve(root->left);

    //     root->right = prev;
    //     root->left = NULL;

    //     prev = root;
    // }
    void flatten(TreeNode* root) {
        //recursive
        // solve(root);

        //using stack
        // if(root == NULL || root->left == NULL && root->right == NULL){
        //     return; 
        // }

        // stack<TreeNode*> st;
        // st.push(root);

        // while(!st.empty()){
        //     TreeNode* curr =  st.top();
        //     st.pop();

        //     if(curr->right){
        //         st.push(curr->right);
        //     }
        //     if(curr->left){
        //         st.push(curr->left);
        //     }

        //     if(!st.empty()){
        //         curr->right = st.top();
        //     }
        //     curr->left = NULL;
        // }


        //without space complexity

        TreeNode* curr = root;
        TreeNode* prev;

        while(curr != NULL){
            
            if(curr->left != NULL){
                prev = curr->left;

                while(prev->right != NULL){
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
