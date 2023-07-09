#define ll long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll ans = 0;
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,ll>> q;
        q.push({root, 0});

        while(!q.empty()){
            ll nmin = q.front().second;
            ll size = q.size();
            ll first, last;

            for(int i = 0; i<size; i++){
                ll curr_id = q.front().second-nmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0){
                    first = curr_id;
                }
                if(i == size-1){
                    last = curr_id;
                }

                if(node->left){
                    q.push({node->left, (curr_id*2)*1LL+1});
                }
                if(node->right){
                    q.push({node->right, (curr_id*2)*1LL+2});
                }  
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
