class Solution {
  public:
  
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]){
        
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto neibour: adj[node]){
            if(!vis[neibour]){
                if(dfsCheck(neibour, adj, vis, pathVis)){
                    return true;
                }
            }
            else if(pathVis[neibour]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        // int vis[V] = {0};
        // int pathVis[V] = {0};
        
        // for(int i = 0; i<V; i++){
        //     if(!vis[i]){
        //         if(dfsCheck(i, adj, vis, pathVis)){
        //             return true;
        //         }
        //     }
        // }
        
        // return false;
        
        //using bfs
       int indegree[V] = {0};
	   
	   for(int i = 0; i<V; i++){
	       for(auto it : adj[i]){
	           indegree[it]++;
	       }
	   }
	   
	   queue<int> q;
	   
	   for(int i = 0; i<V; i++){
	       if(indegree[i] == 0){
	           q.push(i);
	       }
	   }
	   
	   int count = 0;
	   
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       count++;
	       
	       for(auto it : adj[node]){
	           indegree[it]--;
	           if(indegree[it] == 0){
	               q.push(it);
	           }
	           
	       }
	   }
	   if(count == V){
	       return false;
	   }
	   return true;
    }
};
