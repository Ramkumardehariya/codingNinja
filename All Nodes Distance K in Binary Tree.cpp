class Solution {
public:

    void findParent(TreeNode* root, TreeNode* target, unordered_map<TreeNode*,TreeNode*> &markParent){
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                markParent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                markParent[node->right] = node;
                q.push(node->right);
            }
        } 
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*> markParent;
        findParent(root, target, markParent);

        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;

        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();

            if(curr_level++ == k){
                break;
            }
            

            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                } 
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(markParent[node] && !vis[markParent[node]]){
                    q.push(markParent[node]);
                    vis[markParent[node]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            ans.push_back(node->val);
        }

        return ans;
    }
};
