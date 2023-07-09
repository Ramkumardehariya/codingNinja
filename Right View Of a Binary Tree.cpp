void solve(BinaryTreeNode<int>* root, int lvl , vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(lvl == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right, lvl+1, ans);
    solve(root->left, lvl+1, ans);
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    int level = 0;
    solve(root, 0, ans);
    return ans;
}
