//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool bfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int r,int c,vector<pair<int,int>>&v){
        visited[r][c]=true;
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        q.push({r,c});
        v.push_back({r-r,c-c});
        int deltaR[]={1,0,-1,0};
        int deltaC[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newR=row+deltaR[i];
                int newC=col+deltaC[i];
                if(newR>=0 && newR<n && newC>=0 && newC<m && !visited[newR][newC] && grid[newR][newC]==1){
                    visited[newR][newC]=true;
                    v.push_back({newR-r,newC-c});
                    q.push({newR,newC});
                }
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
       set<vector<pair<int,int>>>s;
       int n=grid.size(),m=grid[0].size();
       vector<vector<bool>>visited(n,vector<bool>(m,false));
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(!visited[i][j] && grid[i][j]==1){
                   vector<pair<int,int>>v;
                   bfs(grid,visited,i,j,v);
                   s.insert(v);
               }
           }
       }
       return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends