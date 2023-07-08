class Solution {
  public:
  
    int solve(Node* root, int &d){
        if(root == NULL){
            return 0;
        }
        
        int lh = solve(root->left, d);
        int rh = solve(root->right , d);
        d = max(d, lh+rh);
        
        return 1 + max(lh,rh);
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int diameter = 0;
        solve(root, diameter);
        return diameter+1;
    }
};
