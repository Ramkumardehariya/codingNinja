class Solution {
public:

    bool dfs(int node,vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<vector<int>>& graph){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, check, graph) == true){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> check(n,0);

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, check, graph);
            }
        }

        vector<int> ans;

        for(int i = 0 ; i<n; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
