vector <int> preInPostOrderTraversal(Node* root)
{
  vector<int> in, pre, post;
  if(root == NULL){
      return in;
  }
  stack<pair<Node*,int>> st;
  st.push({root, 1});
  
  while(!st.empty()){
      auto temp = st.top();
      st.pop();
      
      if(temp.second == 1){
          pre.push_back(temp.first->data);
          temp.second++;
          st.push(temp);
          
          if(temp.first->left){
              st.push({temp.first->left, 1});
          }
      }
      else if(temp.second == 2){
          in.push_back(temp.first->data);
          temp.second++;
          st.push(temp);
          
          if(temp.first->right){
              st.push({temp.first->right, 1});
          }
      }
      else{
          post.push_back(temp.first->data);
      }
  }
}
