//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    void dfs(int start, vector<vector<int>> &adj, vector<int> &visited, stack<int> &s)
    {
        visited[start] = 1;
        for (auto it : adj[start])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited, s);
                s.push(it);
            }
        }
    }
    void dfs1(int start, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[start] = 1;
        for (auto it : adj[start])
        {
            if (!visited[it])
            {
                dfs1(it, adj, visited);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // traverse with dfs in the whole graph
        vector<int> visited(V, 0);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, s);
                s.push(i);
            }
        }
        vector<vector<int>> adjRev(V);
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for (auto it : adj[i])
            {
                adjRev[it].push_back(i);
            }
        }
        int cnt = 0;
        while (!s.empty())
        {
            int curr = s.top();
            s.pop();
            if (visited[curr])
                continue;

            dfs1(curr, adjRev, visited);
            cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends