//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
  bool dfs(vector<int> graph[], int start_vertex, vector<int> &visited,
         vector<int> &path)
  {
    visited[start_vertex] = 1;
    for (auto it : graph[start_vertex])
    {
        if (!visited[it])
        {
            if (dfs(graph, it, visited, path))
            {
                visited[it] = 2;
                return true;
            }
            path[it] = 1;
        }
        else if (visited[it] == 1 && path[it]==0){
         visited[it]=2;
         return true;   
        }
        else if(visited[it]==2){
            visited[start_vertex]=2;
            return true;
            
        }
    }
    return false;
   }

public:
vector<int> eventualSafeNodes(int v, vector<int> graph[])
{
    vector<int> visited(v, 0);
    vector<int> path(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (dfs(graph, i, visited, path))
                visited[i] = 2;
            path[i] = 1;
        }
    }
    vector<int> soln;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 1)
            soln.push_back(i);
    }
    sort(soln.begin(), soln.end());
    return soln;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends