class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int>adj[V];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
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
       if(soln.size()==V)return soln;
       else return {};
           
    }
};