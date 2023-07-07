#include<bits/stdc++.h>
using namespace std;

class DisJointSet{
    vector<int> parent, rank, size;

    public:
    DisJointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
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

    void unionByRank(int u, int v){
        int par_u = findParent(u);
        int par_v = findParent(v);

        if(par_u == par_v){
            return;
        }
        if(rank[par_u] < rank[par_v]){
            parent[par_u] = par_v;
        }
        else if(rank[par_v] < rank[par_u]){
            parent[par_v] = par_u;
        }
        else{
            parent[par_v] = par_u;
            rank[par_u]++;
        }
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

int main(){
    DisJointSet s(7);
    // s.unionByRank(1, 2);
    // s.unionByRank(2, 3);
    // s.unionByRank(4, 5);
    // s.unionByRank(6, 7);
    // s.unionByRank(5, 6);

    s.unionBySize(1, 2);
    s.unionBySize(2, 3);
    s.unionBySize(4, 5);
    s.unionBySize(6, 7);
    s.unionBySize(5, 6);

    if(s.findParent(3) == s.findParent(7)){
        cout<<"parent is same"<<endl;
    }
    else{
        cout<<"parent is not Same"<<endl;
    }

    // s.unionByRank(3, 7);
    s.unionBySize(3, 7);

    if(s.findParent(3) == s.findParent(7)){
        cout<<"parent is same"<<endl;
    }
    else{
        cout<<"parent is not Same"<<endl;
    }
    return 0;
}
