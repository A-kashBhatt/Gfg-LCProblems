//memoization solution
class Solution {
    int helper(int amount,vector<int>&coins,int start,vector<vector<int>>&dp){
        if(amount==0)return 1;
        if(amount<0||start>=coins.size())return 0;
        if(dp[amount][start]!=-1)return dp[amount][start];
        int ans=0;
        // for(int i=start;i<coins.size();i++){
        //     if(coins[i]>amount)return 0;
        //     ans+=helper(amount-coins[i],coins,i,dp);
        // }
        ans+=helper(amount-coins[start],coins,start,dp);
        ans+=helper(amount,coins,start+1,dp);
        
        return dp[amount][start]=ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        int sz=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(amount+1,vector<int>(sz,-1));
        return helper(amount,coins,0,dp);
        
    }
};