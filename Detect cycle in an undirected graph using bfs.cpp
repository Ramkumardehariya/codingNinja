class Solution {
  public:
  
    bool detectCycle(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        
        queue<pair<int,int>> q;
        
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto neibour : adj[node]){
                if(!vis[neibour]){
                    vis[neibour] = 1;
                    q.push({neibour, node});
                }
                else if(parent != neibour){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(detectCycle(i, adj, vis)){
                    return true;
                }
            }
            
        }
        
        return false;
    }
};
