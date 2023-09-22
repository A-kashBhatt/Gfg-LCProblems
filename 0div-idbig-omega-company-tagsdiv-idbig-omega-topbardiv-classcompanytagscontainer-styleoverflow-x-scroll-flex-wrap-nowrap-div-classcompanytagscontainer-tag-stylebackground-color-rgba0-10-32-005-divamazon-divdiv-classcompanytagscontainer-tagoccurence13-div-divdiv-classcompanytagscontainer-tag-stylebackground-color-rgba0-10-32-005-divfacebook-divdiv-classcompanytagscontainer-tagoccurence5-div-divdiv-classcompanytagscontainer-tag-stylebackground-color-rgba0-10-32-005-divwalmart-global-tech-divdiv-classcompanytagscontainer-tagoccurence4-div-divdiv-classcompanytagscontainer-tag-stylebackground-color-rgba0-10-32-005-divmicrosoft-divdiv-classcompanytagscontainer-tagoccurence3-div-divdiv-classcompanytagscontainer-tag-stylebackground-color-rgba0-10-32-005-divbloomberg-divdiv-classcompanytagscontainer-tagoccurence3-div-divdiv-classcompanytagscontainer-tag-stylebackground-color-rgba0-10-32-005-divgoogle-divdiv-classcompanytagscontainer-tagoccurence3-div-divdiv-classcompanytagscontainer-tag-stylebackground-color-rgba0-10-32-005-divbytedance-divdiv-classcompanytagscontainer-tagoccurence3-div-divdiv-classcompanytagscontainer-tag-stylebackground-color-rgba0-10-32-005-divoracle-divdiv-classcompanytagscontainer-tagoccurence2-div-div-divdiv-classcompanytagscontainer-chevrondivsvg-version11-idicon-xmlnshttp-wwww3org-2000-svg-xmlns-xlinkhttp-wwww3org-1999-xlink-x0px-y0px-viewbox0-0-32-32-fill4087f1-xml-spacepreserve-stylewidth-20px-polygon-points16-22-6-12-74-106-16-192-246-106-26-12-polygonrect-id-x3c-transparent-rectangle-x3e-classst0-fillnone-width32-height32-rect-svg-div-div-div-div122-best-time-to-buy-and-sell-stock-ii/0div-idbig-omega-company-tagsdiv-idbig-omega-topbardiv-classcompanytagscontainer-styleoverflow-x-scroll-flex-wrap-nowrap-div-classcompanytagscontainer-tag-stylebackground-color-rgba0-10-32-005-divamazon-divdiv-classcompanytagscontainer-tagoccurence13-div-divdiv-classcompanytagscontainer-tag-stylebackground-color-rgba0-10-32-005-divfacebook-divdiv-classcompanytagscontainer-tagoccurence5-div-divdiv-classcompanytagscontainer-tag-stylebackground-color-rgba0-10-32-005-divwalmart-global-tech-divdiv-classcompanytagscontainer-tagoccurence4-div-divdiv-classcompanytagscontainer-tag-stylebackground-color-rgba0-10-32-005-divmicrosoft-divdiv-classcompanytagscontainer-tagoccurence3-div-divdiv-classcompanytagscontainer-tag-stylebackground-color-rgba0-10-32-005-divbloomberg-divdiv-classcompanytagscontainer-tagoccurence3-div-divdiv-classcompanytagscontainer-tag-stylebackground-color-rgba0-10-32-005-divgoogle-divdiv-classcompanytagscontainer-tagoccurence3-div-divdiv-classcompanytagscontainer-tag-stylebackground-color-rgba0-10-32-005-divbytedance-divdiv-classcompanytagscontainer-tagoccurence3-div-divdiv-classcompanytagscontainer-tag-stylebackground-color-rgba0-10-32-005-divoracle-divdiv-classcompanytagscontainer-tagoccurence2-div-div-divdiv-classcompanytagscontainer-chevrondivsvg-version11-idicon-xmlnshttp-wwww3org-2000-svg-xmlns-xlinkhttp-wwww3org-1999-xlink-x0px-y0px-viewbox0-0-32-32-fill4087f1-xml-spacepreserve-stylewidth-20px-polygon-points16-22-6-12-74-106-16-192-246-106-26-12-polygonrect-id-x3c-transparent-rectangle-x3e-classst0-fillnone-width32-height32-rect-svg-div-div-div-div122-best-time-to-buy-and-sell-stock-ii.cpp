//Memoization
class Solution {
    int helper(vector<int>&prices,int ind,int buy,vector<vector<int>>&dp){
        if(ind==prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
          return  dp[ind][buy]=max(-prices[ind]+helper(prices,ind+1,0,dp),
                     helper(prices,ind+1,1,dp));
        }
        else{
          return  dp[ind][buy]=max(prices[ind]+helper(prices,ind+1,1,dp),
                     helper(prices,ind+1,0,dp));
        }
    }
    
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper(prices,0,1,dp);
    }
};