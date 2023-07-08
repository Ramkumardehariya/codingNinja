class Solution {
public:
    // vector<int> ans;
    // void solve(TreeNode* root){
    //     if(root == NULL){
    //         return;
    //     }
    //     solve(root->left);
    //     solve(root->right);
    //     ans.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        // solve(root);

        //iterative using one stack
        // vector<int> ans;
        // if(root == NULL){
        //     return ans;
        // }
        // stack<TreeNode*> st1, st2;
        // st1.push(root);

        // while(!st1.empty()){
        //     root = st1.top();
        //     st1.pop();
        //     st2.push(root);

        //     if(root->left){
        //         st1.push(root->left);
        //     }
        //     if(root->right){
        //         st1.push(root->right);
        //     }
        // }
        // while(!st2.empty()){
        //     ans.push_back(st2.top()->val);
        //     st2.pop();
        // }
        // return ans;

        //itrarative using two stack
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        TreeNode *temp = NULL;
        while (curr != NULL || !st.empty())
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                if (curr->right == NULL || curr->right == temp)
                {
                    ans.push_back(curr->val);
                    st.pop();
                    temp = curr;
                    curr = NULL;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
