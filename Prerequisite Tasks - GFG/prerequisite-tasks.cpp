//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[V];
	    for(auto it:prerequisites){
	        adj[it.second].push_back(it.first);
	    }
	    vector<int>inDegree(V,0);
	   for(int i=0;i<V;i++){
	       for(auto x:adj[i]){
	           inDegree[x]++;
	       }
	   }
	   vector<int>soln;
	   queue<int>q;
	   for(int i=0;i<V;i++){
	       if(inDegree[i]==0){
	           q.push(i);
	           soln.push_back(i);
	       }
	   }
	   while(!q.empty()){
	   
	   int curr=q.front();
	   q.pop();
	   for(auto x:adj[curr]){
	       inDegree[x]--;
	       if(inDegree[x]==0){
	           q.push(x);
	           soln.push_back(x);
	       }
	   }
	       
	   }
	   return (soln.size()==V);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends