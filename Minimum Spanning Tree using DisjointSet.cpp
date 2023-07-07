class DisJointSet{
    vector<int> parent, size;

    public:
    DisJointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int par_u = findParent(u);
        int par_v = findParent(v);

        if(par_u == par_v){
            return ;
        }
        if(size[par_u] < size[par_v]){
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        else{
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int,int>>> edges;
        
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                int wt = it[1];
                int adjNode = it[0];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        DisJointSet s(V);
        int mst = 0;
        
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(s.findParent(u) != s.findParent(v)){
                mst += wt;
                s.unionBySize(u, v);
            }
        }
        return mst;
    }
};
