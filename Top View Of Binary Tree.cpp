
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> mp;

    queue<pair<TreeNode<int>*,int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        TreeNode<int>* node = it.first;
        int top = it.second;

        if(mp.find(top) == mp.end()){
            mp[top] = node->val;
        }
        if(node->left){
            q.push({node->left, top-1});
        }
        if(node->right){
            q.push({node->right, top+1});
        }
    }

    for(auto node : mp){
        ans.push_back(node.second);
    }
    return ans;
}
