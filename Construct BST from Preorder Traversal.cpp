TreeNode<int>* solve(vector<int> &a, int &i, int bound){
    if(i >= a.size() || a[i] > bound){
        return NULL;
    }

    TreeNode<int>* root = new TreeNode<int> (a[i++]);
    root->left = solve(a, i, root->data);
    root->right = solve(a, i, bound);

    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i = 0;
    return solve(preOrder, i, INT_MAX);
}
