vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> mp;
    queue<pair<BinaryTreeNode<int>*,int>> q;

    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        BinaryTreeNode<int>* node = it.first;
        int hd = it.second;
        mp[hd] = node->data;

        if(node->left){
            q.push({node->left, hd-1});
        }
        if(node->right){
            q.push({node->right, hd+1});
        }
    }


    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}
