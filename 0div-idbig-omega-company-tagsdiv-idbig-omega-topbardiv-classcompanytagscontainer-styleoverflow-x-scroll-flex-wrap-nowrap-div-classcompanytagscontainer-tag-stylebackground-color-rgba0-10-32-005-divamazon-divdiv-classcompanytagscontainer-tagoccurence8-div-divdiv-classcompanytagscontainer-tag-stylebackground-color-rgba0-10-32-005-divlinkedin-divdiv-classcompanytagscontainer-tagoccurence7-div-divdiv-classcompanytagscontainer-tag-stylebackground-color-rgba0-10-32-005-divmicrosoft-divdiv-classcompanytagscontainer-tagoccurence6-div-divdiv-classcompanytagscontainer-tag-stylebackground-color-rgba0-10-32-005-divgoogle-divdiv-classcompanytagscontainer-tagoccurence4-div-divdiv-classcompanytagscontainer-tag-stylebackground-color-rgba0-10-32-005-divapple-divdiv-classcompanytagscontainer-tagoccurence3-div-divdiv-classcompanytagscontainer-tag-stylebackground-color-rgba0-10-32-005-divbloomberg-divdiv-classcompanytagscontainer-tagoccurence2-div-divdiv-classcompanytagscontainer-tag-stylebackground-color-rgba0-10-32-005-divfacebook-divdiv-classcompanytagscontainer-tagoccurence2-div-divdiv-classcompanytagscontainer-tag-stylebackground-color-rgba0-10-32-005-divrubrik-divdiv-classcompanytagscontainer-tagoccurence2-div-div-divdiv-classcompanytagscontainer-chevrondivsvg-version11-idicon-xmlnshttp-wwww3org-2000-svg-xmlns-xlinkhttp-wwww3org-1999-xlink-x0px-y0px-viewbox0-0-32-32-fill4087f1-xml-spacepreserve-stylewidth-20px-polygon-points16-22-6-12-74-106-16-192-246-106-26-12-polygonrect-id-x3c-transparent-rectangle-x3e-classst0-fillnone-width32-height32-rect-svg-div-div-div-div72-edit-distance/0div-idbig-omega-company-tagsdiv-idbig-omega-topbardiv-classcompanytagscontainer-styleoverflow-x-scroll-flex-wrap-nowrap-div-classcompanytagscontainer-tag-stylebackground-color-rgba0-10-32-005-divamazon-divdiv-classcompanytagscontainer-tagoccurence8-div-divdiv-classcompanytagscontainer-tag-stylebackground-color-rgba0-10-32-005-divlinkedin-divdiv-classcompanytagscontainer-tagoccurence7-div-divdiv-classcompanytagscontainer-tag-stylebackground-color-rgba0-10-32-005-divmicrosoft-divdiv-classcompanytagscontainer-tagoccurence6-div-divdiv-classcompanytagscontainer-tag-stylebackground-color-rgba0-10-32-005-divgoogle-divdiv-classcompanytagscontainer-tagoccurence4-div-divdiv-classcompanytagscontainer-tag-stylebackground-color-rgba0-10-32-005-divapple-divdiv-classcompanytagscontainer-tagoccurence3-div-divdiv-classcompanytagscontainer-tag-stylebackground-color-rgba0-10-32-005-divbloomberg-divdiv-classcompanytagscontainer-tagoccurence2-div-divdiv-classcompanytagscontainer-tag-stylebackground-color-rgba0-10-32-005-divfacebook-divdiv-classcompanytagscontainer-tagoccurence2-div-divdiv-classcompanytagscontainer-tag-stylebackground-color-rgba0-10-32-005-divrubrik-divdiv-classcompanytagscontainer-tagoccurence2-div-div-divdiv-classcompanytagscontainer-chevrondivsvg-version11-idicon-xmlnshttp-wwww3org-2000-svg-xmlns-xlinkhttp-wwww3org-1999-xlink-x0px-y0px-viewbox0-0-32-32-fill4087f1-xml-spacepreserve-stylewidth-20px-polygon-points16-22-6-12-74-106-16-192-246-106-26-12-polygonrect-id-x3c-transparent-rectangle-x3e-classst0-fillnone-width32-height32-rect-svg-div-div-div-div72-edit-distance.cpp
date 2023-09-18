class Solution {
    int helper(string word1, string word2,int i,int j,vector<vector<int>>&dp){
        if(i==word1.size() && j==word2.size())return 0;
        if(i==word1.size())return (word2.size()-j);
        if(j==word2.size())return (word1.size()-i);
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])return helper(word1,word2,i+1,j+1,dp);
        //replace
        
        int replace= 1+helper(word1,word2,i+1,j+1,dp);
        
        //insert
        
        int insert= 1+helper(word1,word2,i,j+1,dp);
            
        //remove
        
        int remove= 1+helper(word1,word2,i+1,j,dp);
        return dp[i][j]=min(replace,min(insert,remove));
    }
public:
    int minDistance(string word1, string word2) {
        int sz1=word1.size(),sz2=word2.size();
        vector<vector<int>>dp(sz1,vector<int>(sz2,-1));
        return helper(word1,word2,0,0,dp);
    }
};