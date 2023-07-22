//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // Mark all vertices as unvisited
        queue<pair<int, int>> q;
        vector<vector<char>> soln(mat.begin(), mat.end());

        for (int i = 0; i < n; i ++)
        {
            if (!visited[i][0] && mat[i][0] == 'O')
            {
                visited[i][0] = true;
                q.push({i, 0});
            }
            if (!visited[i][m - 1] && mat[i][m - 1] == 'O')
            {
                visited[i][m - 1] = true;
                q.push({i, m - 1});
            }
        }
        for (int i = 0; i < m; i++)
        {

            if (!visited[0][i] && mat[0][i] == 'O')
            {
                visited[0][i] = true;
                q.push({0, i});
            }

            if (!visited[n - 1][i] && mat[n - 1][i] == 'O')
            {
                visited[n - 1][i] = true;
                q.push({n - 1, i});
            }
        }

        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newR = row + delRow[i];
                int newC = col + delCol[i];
                if (newR >= 0 && newC >= 0 && newR < n && newC < m && !visited[newR][newC] && mat[newR][newC] == 'O')
                {
                    visited[newR][newC] = true;
                    q.push({newR, newC});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && mat[i][j] == 'O')
                    soln[i][j] = 'X';
            }
        }
        return soln;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends