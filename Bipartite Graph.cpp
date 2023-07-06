class Solution {
public:

    bool bfs(int start, int color[], vector<int> adj[]){
        
        color[start] = 0;
        
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto neibour : adj[node]){
                if(color[neibour] == -1){
                    color[neibour] = !color[node];
                    q.push(neibour);
                }
                else if(color[neibour] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool dfs(int node, int col, int color[], vector<int> adj[]){
        
        color[node] = col;
        
        for(auto neibour : adj[node]){
            if(color[neibour] == -1){
                
                if(dfs(neibour, !col, color, adj) == false){
                    return false;
                }
            }
            else if(color[neibour] == col){
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    
	    int color[V];
	    
	    for(int i = 0; i<V; i++){
	        color[i] = -1;
	    }
	    
	    for(int i = 0; i<V; i++){
	        if(color[i] == -1){
	           // if(bfs(i, color, adj) == false){
	           //     return false;
	           // }
	           if(dfs(i,0, color, adj) == false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};
