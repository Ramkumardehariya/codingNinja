class Solution {
  public:
  
    void dfs(int node, vector<int> &ans, queue<int> q, vector<int> adj[], int vis[]){
        
        vis[node] = 1;
        
        ans.push_back(node);
        
        for(auto neibour : adj[node]){
            if(!vis[neibour]){
                dfs(neibour, ans, q, adj, vis);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        int start = 0;
        
        queue<int> q;
        
        vector<int> ans;
        
        dfs(start, ans, q, adj, vis);
        
        return ans;
    }
};
