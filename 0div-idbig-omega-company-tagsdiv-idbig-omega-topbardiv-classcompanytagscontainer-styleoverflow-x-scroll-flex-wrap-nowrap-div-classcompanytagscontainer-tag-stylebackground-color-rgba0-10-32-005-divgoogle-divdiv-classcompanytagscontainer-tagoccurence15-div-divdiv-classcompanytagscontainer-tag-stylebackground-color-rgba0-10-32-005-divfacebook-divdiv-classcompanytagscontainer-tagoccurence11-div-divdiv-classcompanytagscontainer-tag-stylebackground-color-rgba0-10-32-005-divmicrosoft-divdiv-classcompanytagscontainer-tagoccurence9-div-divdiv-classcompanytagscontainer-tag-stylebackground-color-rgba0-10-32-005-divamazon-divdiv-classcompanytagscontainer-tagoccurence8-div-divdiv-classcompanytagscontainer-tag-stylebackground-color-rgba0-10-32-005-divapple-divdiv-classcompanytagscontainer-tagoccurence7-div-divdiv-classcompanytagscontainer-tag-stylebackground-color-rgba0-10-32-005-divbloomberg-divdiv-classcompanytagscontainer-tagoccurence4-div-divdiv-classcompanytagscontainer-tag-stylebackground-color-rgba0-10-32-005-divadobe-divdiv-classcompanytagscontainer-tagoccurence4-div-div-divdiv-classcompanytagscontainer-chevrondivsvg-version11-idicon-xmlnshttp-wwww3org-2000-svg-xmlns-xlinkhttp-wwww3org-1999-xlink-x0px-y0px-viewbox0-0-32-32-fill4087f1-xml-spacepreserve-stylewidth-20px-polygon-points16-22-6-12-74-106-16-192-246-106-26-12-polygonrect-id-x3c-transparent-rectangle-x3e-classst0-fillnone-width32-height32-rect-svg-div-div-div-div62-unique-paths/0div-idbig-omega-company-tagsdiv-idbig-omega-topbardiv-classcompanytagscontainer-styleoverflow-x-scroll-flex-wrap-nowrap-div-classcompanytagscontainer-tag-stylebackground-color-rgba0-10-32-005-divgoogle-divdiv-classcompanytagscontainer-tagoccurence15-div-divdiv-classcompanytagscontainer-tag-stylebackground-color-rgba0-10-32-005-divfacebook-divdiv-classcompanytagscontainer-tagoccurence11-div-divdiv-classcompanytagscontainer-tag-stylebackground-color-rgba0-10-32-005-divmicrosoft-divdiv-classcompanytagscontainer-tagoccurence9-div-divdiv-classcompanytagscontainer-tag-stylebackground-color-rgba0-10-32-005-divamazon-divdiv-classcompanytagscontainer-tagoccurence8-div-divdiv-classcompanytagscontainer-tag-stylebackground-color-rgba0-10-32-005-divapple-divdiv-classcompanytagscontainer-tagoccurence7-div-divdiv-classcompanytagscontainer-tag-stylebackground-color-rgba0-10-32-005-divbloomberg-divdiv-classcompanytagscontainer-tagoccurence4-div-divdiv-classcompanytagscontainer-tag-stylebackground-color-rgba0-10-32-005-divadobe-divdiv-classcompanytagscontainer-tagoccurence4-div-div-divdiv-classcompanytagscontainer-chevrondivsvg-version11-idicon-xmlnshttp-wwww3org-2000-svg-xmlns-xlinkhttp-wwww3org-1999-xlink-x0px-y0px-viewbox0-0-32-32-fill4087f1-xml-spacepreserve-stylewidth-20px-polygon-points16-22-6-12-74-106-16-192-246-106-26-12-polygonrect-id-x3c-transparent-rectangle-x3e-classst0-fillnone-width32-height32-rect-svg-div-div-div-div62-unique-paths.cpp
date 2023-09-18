class Solution {
    int helper(int m,int n,vector<vector<int>>&dp){
        if(n==0 && m==0)return 1;
        if(dp[m][n]!=-1)return dp[m][n];
        //top ways and left ways
        int top=0,left=0;
        if(m-1>=0)top=helper(m-1,n,dp);
        if(n-1>=0)left=helper(m,n-1,dp);
        return dp[m][n]=top+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
};