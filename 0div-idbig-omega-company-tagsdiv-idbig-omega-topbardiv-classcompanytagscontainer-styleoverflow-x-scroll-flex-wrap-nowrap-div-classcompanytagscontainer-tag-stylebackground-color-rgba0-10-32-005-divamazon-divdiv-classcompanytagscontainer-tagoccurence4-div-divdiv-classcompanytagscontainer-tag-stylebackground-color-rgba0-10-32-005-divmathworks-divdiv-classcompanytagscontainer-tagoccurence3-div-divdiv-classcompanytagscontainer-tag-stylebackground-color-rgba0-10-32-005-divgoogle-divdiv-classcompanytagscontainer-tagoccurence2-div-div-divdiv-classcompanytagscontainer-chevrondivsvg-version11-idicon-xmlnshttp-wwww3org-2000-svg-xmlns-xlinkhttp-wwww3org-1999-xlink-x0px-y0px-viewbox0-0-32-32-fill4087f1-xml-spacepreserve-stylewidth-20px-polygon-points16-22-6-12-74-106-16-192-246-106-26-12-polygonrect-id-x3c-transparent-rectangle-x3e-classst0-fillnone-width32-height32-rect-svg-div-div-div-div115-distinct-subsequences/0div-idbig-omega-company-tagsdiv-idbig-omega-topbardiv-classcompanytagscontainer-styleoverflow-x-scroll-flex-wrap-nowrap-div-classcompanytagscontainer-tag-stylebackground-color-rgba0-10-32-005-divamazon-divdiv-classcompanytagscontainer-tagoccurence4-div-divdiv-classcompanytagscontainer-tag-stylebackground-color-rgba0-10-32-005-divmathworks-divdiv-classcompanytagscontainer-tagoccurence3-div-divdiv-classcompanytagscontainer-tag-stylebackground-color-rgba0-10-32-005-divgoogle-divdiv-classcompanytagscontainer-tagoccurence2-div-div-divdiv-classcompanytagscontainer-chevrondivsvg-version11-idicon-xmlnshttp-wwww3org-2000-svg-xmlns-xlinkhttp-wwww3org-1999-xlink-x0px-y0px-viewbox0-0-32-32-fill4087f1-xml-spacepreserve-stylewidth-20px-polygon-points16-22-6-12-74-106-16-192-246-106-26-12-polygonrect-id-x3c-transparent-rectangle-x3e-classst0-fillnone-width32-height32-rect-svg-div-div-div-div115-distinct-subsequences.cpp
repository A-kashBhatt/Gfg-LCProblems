class Solution {
    
int helper(string &str, string &sub,int i,int j,vector<vector<int>>&dp){
	if(j<0)return 1;
	if(i<0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int take=0,notTake=0;
	if(str[i]==sub[j])take=helper(str,sub,i-1,j-1,dp);
    notTake=helper(str,sub,i-1,j,dp);
	return dp[i][j]=take+notTake;
}
public:
    int numDistinct(string str, string sub) {
        int sz1=str.size(),sz2=sub.size();
	if(sz2>sz1)return 0;
	vector<vector<int>>dp(sz1,vector<int>(sz2,-1));
	return helper(str,sub,sz1-1,sz2-1,dp);
    }
};