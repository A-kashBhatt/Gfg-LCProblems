//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(vector<vector<int>> &graph, int start_vertex,vector<bool>&visited)
{
    int num_vertices = graph.size();

    stack<int> s;
    s.push(start_vertex);
    visited[start_vertex] = true;

    while (!s.empty())
    {
        int current_vertex = s.top();
        s.pop();
        for (int i=0;i<graph[0].size();i++)
        {
            if (!visited[i] && graph[current_vertex][i])
            {
                visited[i] = true;
                s.push(i);
            }
        }
    }
}
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V, false); // Mark all vertices as unvisited
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                cnt++;
                dfs(adj,i,visited);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends