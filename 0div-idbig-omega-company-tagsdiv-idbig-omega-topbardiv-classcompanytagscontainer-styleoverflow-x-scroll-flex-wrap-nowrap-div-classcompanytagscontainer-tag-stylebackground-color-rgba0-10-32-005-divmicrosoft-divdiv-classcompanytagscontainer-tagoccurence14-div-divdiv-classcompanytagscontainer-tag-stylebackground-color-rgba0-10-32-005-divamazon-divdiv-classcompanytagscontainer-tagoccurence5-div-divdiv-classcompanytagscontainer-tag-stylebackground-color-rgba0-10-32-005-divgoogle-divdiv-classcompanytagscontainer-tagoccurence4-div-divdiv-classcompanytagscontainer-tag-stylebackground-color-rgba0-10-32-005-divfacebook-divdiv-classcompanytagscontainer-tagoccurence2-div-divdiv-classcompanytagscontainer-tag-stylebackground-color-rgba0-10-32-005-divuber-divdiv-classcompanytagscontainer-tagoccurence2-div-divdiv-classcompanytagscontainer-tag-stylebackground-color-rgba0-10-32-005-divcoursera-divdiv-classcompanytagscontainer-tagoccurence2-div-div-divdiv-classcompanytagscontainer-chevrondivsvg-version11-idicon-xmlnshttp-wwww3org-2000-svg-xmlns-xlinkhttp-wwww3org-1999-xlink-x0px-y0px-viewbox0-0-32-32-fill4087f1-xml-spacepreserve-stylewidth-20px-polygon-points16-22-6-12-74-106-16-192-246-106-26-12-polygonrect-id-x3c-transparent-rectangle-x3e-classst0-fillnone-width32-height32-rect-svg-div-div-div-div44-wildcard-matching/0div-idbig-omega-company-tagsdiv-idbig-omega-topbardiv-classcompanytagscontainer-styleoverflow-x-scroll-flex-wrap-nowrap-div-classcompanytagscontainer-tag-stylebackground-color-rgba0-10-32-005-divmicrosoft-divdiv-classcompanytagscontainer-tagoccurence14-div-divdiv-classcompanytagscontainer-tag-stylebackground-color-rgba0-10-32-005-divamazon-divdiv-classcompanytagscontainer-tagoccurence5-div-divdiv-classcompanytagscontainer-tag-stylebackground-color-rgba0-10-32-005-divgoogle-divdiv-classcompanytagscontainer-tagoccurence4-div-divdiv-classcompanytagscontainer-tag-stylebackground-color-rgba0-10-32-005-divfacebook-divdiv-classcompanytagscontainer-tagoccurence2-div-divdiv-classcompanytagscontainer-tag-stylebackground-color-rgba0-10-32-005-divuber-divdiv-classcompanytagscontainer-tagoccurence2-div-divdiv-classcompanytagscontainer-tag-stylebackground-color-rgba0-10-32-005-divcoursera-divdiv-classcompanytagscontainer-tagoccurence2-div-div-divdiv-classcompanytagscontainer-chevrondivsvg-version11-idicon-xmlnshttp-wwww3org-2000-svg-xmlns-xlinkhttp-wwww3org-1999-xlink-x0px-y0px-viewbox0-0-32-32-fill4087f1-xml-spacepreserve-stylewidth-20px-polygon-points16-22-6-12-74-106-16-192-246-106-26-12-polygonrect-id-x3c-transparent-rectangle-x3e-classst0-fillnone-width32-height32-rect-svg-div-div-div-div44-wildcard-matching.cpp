class Solution {

public:
    bool isMatch(string s, string p) {
        int sz1=s.size(),sz2=p.size();
        vector<vector<bool>>dp(sz1+1,vector<bool>(sz2+1,false));
        dp[0][0]=true;
        for(int i=1;i<=sz1;i++)dp[i][0]=false;
        bool extraChar=false;
        for(int j=1;j<=sz2;j++){
            if(p[j-1]!='*')extraChar=true;
            if(extraChar)break;
            dp[0][j]=true;
        }
        for(int i=1;i<=sz1;i++){
            for(int j=1;j<=sz2;j++){
                if((s[i-1]==p[j-1])||p[j-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j]=(dp[i-1][j] | dp[i][j-1]);
                }
                else dp[i][j]=false;
            }
        }
        return dp[sz1][sz2];
    }
};