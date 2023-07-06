class Solution {
  public:
    bool detectCycle(int node , int parent, vector<int> adj[], int vis[]){
        vis[node] = 1;
        
        for(auto neibour : adj[node]){
            if(!vis[neibour]){
                if(detectCycle(neibour, node, adj, vis)){
                    return true;
                }
            }
            else if(neibour != parent){
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(detectCycle(i,-1, adj, vis)){
                    return true;
                }
            }
            
        }
        
        return false;
    }
};
