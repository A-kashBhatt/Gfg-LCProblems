//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
void bfs(vector<vector<int>>& image,vector<vector<int>>&soln,vector<vector<int>>&visited, int sr, int sc, int newColor, int currColor)
     {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = 1;
    soln[sr][sc]=newColor;
    int n = image.size(), m = image[0].size();
    while (!q.empty())
    {
       int r = q.front().first;
       int c = q.front().second;
        q.pop();
        int dR[4]={1,0,-1,0};
        int dC[4]={0,1,0,-1};
        for (int i = 0; i < 4; i++)
        {
                int cr = r + dR[i], cc = c + dC[i];
                if (cr >= 0 && cr < n && cc >= 0 && cc < m && !visited[cr][cc]  && image[cr][cc] == currColor)
                {
                    visited[cr][cc] = 1;
                    soln[cr][cc]=newColor;
                    q.push({cr, cc});
                }
        }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
                vector<vector<int>> visited(n, vector<int>(m, 0));
                vector<vector<int>>soln(image.begin(),image.end());
                int currColor=image[sr][sc];
                bfs(image,soln,visited,sr,sc,newColor,currColor);
                return soln;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends