class Solution {
public:

    bool solve(TreeNode* root, long min, long max){
        if(root == NULL){
            return true;
        }
        if(root->val >= max || root->val <= min){
            return false;
        }
        bool left = solve(root->left, min, root->val);
        bool right = solve(root->right, root->val, max);
        return  left && right;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
