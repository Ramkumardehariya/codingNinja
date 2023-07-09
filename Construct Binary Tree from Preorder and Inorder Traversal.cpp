class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& inMap){
        if(inStart > inEnd || preStart > preEnd){
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preStart]);

        int inRoot = inMap[node->val];
        int numsLeft = inRoot - inStart;

        node->left = solve(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap);
        node->right = solve(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i = 0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1,inMap);
        return root;
    }
};
