//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{   public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n = grid.size(),m=grid[0].size();
       vector<vector<bool>> visited(n, vector<bool>(m,false)); // Mark all vertices as unvisited
       queue<pair<pair<int,int>,int>>q;
       int totalOne=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==2){
                   visited[i][j]=true;
                   q.push({{i,j},0});
               }
               else if(grid[i][j]==1)totalOne++;
           }
       }
       if(totalOne==0)return 0;
    int delRow[]={1,0,-1,0};
    int delCol[]={0,1,0,-1};
    int time=0;
    while (!q.empty())
    {   
        int row = q.front().first.first;
        int col=q.front().first.second;
        int currTime=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newR=row+delRow[i];
            int newC=col+delCol[i];
            if(newR>=0 && newC>=0 && newR<n && newC<m && !visited[newR][newC] && grid[newR][newC]==1){
                visited[newR][newC]=true;
                q.push({{newR,newC},currTime+1});
                time=max(time,currTime+1);
                totalOne--;
                if(totalOne==0)return time;
            }
        }
    }
    return -1;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends