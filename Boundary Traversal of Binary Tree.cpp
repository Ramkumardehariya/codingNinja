#include <bits/stdc++.h>

void addLeftNode(TreeNode<int>* root, vector<int> &res){
    TreeNode<int>* curr = root->left;

    while(curr){
        if(curr->left != NULL || curr->right != NULL){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

void addLeave(TreeNode<int>* root, vector<int> &ans){
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    if(root->left){
        addLeave(root->left, ans);
    }
    if(root->right){
        addLeave(root->right, ans);
    }
}

void addRight(TreeNode<int>* root, vector<int> &ans){
    vector<int> temp;
    TreeNode<int>* curr = root->right;

    while(curr){
        if(curr->left != NULL || curr->right != NULL){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }

    for(int i = temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return ans;
    }
    if(root ->left != NULL || root->right != NULL){
        ans.push_back(root->data);
    }
    addLeftNode(root, ans);
    addLeave(root, ans);
    addRight(root, ans);
    return ans;
}
