class Solution {
    bool helper(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        if(i<0 && j<0)return true;
        if(j<0)return false;
        if(i<0){
         int temp=j;
            while(temp>=0){
                if(p[temp]!='*')return false;
                temp--;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if((s[i]==p[j]) || p[j]=='?')return dp[i][j]=helper(s,p,i-1,j-1,dp);
        else if(p[j]=='*'){
            bool take=helper(s,p,i-1,j,dp);
            bool notTake=helper(s,p,i,j-1,dp);
            return dp[i][j]=(take||notTake);
        }
        
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int sz1=s.size(),sz2=p.size();
        vector<vector<int>>dp(sz1,vector<int>(sz2,-1));
        return helper(s,p,sz1-1,sz2-1,dp);
    }
};