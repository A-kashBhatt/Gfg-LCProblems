//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    void helper(vector<vector<int>> &m, int n, vector<vector<int>> &visited,
                vector<string> &soln, string s, int row, int col)
    {
        if(row == n - 1 && col == n - 1) {
            soln.push_back(s);
            return;
        }
        visited[row][col] = 1;
 
        if(row - 1 >= 0 && m[row - 1][col] && visited[row - 1][col] == 0) {
            helper(m, n, visited, soln, s + 'U', row - 1, col);   
        }
               if(row + 1 < n && m[row + 1][col] && visited[row + 1][col] == 0) {
            helper(m, n, visited, soln, s + 'D', row + 1, col);   
        }
        
        if(col + 1 < n && m[row][col + 1] && visited[row][col + 1] == 0) {
            helper(m, n, visited, soln, s + 'R', row, col + 1);   
        }
        
        if(col - 1 >= 0 && m[row][col - 1] && visited[row][col - 1] == 0) {
            helper(m, n, visited, soln, s + 'L', row, col - 1);   
        }
        
        visited[row][col] = 0;
    }
public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> soln;
        if(m[0][0]==0)return soln;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string s = "";
        helper(m, n, visited, soln, s, 0, 0);
        return soln;
    }
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends