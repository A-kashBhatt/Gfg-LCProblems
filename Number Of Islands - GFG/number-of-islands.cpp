//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
    vector<int> rank, parent, size;

public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
          vector<int>visited(n*m,0);
          vector<int>soln;
          DisjointSet ds(n*m);
          int comp=0;
          int deltaRow[]={1,0,-1,0};
          int deltaCol[]={0,1,0,-1};
          for(int i=0;i<operators.size();i++){
              int r=operators[i][0];
              int c=operators[i][1];
              int curr=r*m+c;
              if(visited[curr]==1){
                  soln.push_back(comp);
                  continue;
              }
              else{
                  visited[curr]=1;
                  comp++;
                  for(int j=0;j<4;j++){
                      int newRow=r+deltaRow[j];
                      int newCol=c+deltaCol[j];
                      if(newRow>=0 && newCol>=0 && newRow<n && newCol<m){
                          int newNode=newRow*m+newCol;
                          if(!visited[newNode])continue;
                          else{
                              if(ds.findUPar(curr)!=ds.findUPar(newNode)){
                                  comp--;
                                  ds.unionBySize(curr,newNode);
                              }
                          }
                      }
                  }
                  
              }
              soln.push_back(comp);
          }
        return soln;
    }
    
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends