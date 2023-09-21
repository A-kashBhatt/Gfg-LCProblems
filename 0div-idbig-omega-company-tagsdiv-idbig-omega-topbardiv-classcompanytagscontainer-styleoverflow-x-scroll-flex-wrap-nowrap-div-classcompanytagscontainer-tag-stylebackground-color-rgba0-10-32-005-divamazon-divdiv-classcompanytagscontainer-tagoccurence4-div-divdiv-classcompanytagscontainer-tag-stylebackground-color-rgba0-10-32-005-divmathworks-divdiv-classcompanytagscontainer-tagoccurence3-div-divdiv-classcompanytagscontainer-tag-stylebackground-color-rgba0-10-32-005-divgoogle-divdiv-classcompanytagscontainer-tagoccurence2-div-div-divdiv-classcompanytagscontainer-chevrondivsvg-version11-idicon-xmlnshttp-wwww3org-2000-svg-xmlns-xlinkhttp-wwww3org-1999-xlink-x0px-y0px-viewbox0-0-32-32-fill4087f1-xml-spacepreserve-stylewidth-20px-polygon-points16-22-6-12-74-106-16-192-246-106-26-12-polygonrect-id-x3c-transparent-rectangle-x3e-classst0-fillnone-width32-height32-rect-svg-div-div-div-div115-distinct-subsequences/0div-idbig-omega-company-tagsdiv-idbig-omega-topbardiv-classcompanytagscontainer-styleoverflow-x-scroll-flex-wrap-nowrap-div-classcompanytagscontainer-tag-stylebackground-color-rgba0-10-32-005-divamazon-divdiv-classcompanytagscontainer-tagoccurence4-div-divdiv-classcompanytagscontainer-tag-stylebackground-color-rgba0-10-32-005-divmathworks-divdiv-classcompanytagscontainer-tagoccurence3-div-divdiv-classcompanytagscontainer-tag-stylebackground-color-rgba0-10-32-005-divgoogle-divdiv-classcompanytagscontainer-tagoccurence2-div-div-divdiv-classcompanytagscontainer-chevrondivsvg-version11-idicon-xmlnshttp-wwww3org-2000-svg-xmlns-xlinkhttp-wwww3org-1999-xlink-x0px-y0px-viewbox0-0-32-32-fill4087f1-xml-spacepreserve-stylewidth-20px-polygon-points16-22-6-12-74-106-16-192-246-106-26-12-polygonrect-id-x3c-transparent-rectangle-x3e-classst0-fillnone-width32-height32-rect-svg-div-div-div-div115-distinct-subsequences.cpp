class Solution {
public:
    int numDistinct(string str, string sub) {
        int sz1=str.size(),sz2=sub.size();
	if(sz2>sz1)return 0;
	vector<vector<double>>dp(sz1+1,vector<double>(sz2+1,0));
	for(int i=0;i<=sz1;i++)dp[i][0]=1;
	for(int i=1;i<=sz1;i++){
		for(int j=1;j<=sz2;j++){
			double take=0,notTake=0;
	        if(str[i-1]==sub[j-1])take=dp[i-1][j-1];
            notTake=dp[i-1][j];
	        dp[i][j]=take+notTake;
		}
	}
	return (int)dp[sz1][sz2];
    }
};