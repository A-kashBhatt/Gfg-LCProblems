class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int a=INT_MAX,b=INT_MAX;
                if(i-1>=0)a=grid[i][j]+dp[i-1][j];
                if(j-1>=0)b=grid[i][j]+dp[i][j-1];
                dp[i][j]=min(a,b);
            }
        }
        return dp[m-1][n-1];
    }
};