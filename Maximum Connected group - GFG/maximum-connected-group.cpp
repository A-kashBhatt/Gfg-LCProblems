//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n=grid.size();
        DisjointSet ds(n*n);
        int deltaRow[]={1,0,-1,0};
        int deltaCol[]={0,1,0,-1};
        //making connected components
        int totalZero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int curr=i*n+j;
                if(grid[i][j]){
                    for(int k=0;k<4;k++){
                        int newRow=i+deltaRow[k];
                        int newCol=j+deltaCol[k];
                        if(newRow>=0 && newCol>=0 && newRow<n && newCol<n){
                            if(grid[newRow][newCol]==0)continue;
                            int newNode=newRow*n+newCol;
                            if(ds.findUPar(curr)==ds.findUPar(newNode))continue;
                            else{
                                ds.unionBySize(curr,newNode);
                            }
                        }
                    }
                }
                else totalZero++;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j])continue;
                else{
                    set<int>s;
                    for(int k=0;k<4;k++){
                        int newRow=i+deltaRow[k];
                        int newCol=j+deltaCol[k];
                        if(newRow>=0 && newCol>=0 && newRow<n && newCol<n){
                            int newNode=newRow*n+newCol;
                            if(grid[newRow][newCol]==0)continue;
                            else{
                                s.emplace(ds.findUPar(newNode));
                            }
                        }
                    }
                    int currSize=0;
                    for(auto it:s){
                        currSize+=(ds.size[it]);
                    }
                    maxi=max(currSize+1,maxi);
                }
            }
        }
        return totalZero==0?n*n:maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends