//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    bool dfs(int V, vector<int> adj[],int i,vector<int> &visited,vector<int> &path){
        visited[i]=1;
        for(auto it:adj[i]){
            if(!visited[it]){
                if(dfs(V,adj,it,visited,path))return true;
                path[it]=1;
            }
            else{
                if(path[it]==0)return true;
            }
        }
        return false;
    }
  public:
    
    bool isCyclic(int V, vector<int> adj[]) {
         vector<int>visited(V,0);
         vector<int>path(V,0);
         for(int i=0;i<V;i++){
             if(!visited[i] && dfs(V,adj,i,visited,path))return true;
             path[i]=1;
         }
         return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends