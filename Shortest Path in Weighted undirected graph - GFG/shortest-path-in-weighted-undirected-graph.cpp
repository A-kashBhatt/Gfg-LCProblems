//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       set<pair<int,int>>st;
       st.insert({1,S});
       vector<int>distance(V+1,1e9);
       vector<int>parent(V+1,0);
       distance[S]=0;
       while(!st.empty()){
           auto curr=*(st.begin());
           int node=curr.second;
           int dis=curr.first;
           st.erase(curr);
           for(auto it:adj[node]){
               int adjNode=it[0];
               int edgeWeight=it[1];
               if(distance[adjNode]>dis+edgeWeight){
                   if(distance[adjNode]!=1e9) st.erase({distance[adjNode],adjNode});
                   parent[adjNode]=node;
                   distance[adjNode]=dis+edgeWeight;
                   st.insert({distance[adjNode],adjNode});
               }
           }
       }
       return parent;
    }
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<int>> adj[n+1];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>parent=dijkstra(n,adj,1);
        vector<int>soln;
        if(parent[n]==0)return {-1};
        int child=n;
        while(child!=1){
            soln.push_back(child);
            child=parent[child];
        }
        soln.push_back(1);
        reverse(soln.begin(),soln.end());
        return soln;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends