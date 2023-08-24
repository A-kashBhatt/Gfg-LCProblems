//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       vector<int>soln(V,1e9);
       soln[S]=0;
       pq.push({0,S});
       while(!pq.empty()){
           pair<int,int>curr=pq.top();
           pq.pop();
           int currDistance=curr.first;
           int node=curr.second;
           for(auto it:adj[node]){
               int edgeWeight=it[1];
               int newNode=it[0];
               if(currDistance+edgeWeight<soln[newNode]){
                   soln[newNode]=currDistance+edgeWeight;
                   pq.push({soln[newNode],newNode});
               }
           }
       }
       return soln;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends