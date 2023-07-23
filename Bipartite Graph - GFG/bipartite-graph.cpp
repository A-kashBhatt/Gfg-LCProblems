//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    bool bfs(int V, vector<int>adj[],vector<int>&visited,int start){
        visited[start]=1;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                if(visited[it]==-1){
                    visited[it] = (!visited[curr]);
                    q.push(it);
                }
                else{
                    if(visited[it]==visited[curr])return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>visited(V,-1);
	    for(int i=0;i<V;i++){
	        if(visited[i]==-1 && !bfs(V,adj,visited,i))return false;
	    }
     	return true;    
	}
	

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends