class Solution {
    int timer=1;
    void dfs(int node,int par,vector<int>adj[],vector<int>&visited,
             vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges){
        visited[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==par)continue;
            if(!visited[it]){
                dfs(it,node,adj,visited,tin,low,bridges);
                if(tin[node]<low[it])bridges.push_back({node,it});
            }
            low[node]=min(low[node],low[it]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
        vector<int>tin(n);
        vector<int>low(n);
        vector<vector<int>>bridges;
        dfs(0,-1,adj,visited,tin,low,bridges);
        return bridges;
        
    }
};