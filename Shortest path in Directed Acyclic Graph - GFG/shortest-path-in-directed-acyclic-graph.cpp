//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void topoSort(vector<pair<int,int>>adj[],int start,vector<int>&visited,stack<int>&s){
        visited[start]=1;
        for(auto it:adj[start]){
            if(!visited[it.first]){
                topoSort(adj,it.first,visited,s);
            }
        }
        s.push(start);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        vector<int>visited(N,0);
        stack<int>s;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                topoSort(adj,i,visited,s);
            }
        }
        vector<int>distance(N,INT_MAX);
        distance[0]=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            for(auto it:adj[node]){
                if(distance[node]==INT_MAX)continue;
                if(distance[it.first]>distance[node]+it.second){
                    distance[it.first]=distance[node]+it.second;
                }
            }
            
        }
        for(int i=0;i<N;i++){
            if(distance[i]==INT_MAX)distance[i]=-1;
        }
        return distance;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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