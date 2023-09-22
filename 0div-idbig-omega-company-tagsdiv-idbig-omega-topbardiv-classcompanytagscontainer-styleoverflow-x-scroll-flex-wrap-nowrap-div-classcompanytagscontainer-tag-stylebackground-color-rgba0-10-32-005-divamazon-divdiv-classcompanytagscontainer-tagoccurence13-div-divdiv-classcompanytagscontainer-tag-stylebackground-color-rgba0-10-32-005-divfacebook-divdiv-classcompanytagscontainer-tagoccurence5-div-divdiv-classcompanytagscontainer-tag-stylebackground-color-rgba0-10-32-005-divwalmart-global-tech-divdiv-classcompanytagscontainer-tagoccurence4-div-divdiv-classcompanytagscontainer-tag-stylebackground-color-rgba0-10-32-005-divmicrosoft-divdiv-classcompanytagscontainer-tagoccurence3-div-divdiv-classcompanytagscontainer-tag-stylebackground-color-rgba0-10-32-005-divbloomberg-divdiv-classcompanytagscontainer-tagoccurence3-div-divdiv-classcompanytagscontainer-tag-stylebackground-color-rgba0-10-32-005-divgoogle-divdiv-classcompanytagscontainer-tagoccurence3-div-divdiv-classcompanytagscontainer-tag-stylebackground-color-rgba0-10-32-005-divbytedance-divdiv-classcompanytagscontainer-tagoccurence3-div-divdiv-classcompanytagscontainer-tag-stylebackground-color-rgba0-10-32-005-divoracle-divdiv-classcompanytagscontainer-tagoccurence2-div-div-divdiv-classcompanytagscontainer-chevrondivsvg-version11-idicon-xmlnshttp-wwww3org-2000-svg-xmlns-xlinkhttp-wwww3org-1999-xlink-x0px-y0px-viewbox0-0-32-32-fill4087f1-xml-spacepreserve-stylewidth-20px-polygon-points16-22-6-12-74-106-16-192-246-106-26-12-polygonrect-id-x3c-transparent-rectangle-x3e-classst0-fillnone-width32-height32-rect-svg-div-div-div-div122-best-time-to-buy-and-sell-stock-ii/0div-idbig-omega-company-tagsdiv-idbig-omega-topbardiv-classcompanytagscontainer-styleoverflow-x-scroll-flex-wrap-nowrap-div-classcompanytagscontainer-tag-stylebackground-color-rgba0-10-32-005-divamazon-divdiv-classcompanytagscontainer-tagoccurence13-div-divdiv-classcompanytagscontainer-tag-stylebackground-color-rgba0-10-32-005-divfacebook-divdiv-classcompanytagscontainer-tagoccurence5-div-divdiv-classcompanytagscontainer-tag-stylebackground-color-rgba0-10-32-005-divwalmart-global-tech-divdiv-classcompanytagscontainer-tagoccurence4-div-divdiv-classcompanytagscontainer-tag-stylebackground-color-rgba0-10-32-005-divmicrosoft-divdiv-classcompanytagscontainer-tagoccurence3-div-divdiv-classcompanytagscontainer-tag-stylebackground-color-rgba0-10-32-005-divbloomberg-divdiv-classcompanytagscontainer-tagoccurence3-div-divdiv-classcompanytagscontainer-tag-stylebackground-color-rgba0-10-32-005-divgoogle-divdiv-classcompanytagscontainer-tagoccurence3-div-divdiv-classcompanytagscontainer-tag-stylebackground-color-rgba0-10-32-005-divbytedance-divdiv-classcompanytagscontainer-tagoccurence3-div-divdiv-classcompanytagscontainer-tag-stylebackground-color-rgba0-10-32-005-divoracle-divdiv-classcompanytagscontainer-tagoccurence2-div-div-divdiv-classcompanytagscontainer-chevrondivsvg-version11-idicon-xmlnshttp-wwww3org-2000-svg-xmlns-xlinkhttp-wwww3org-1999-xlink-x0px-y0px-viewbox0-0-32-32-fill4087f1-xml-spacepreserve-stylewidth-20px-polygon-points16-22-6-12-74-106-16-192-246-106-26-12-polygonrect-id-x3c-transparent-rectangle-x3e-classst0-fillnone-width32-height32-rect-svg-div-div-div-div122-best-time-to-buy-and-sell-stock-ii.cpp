//Memoization
class Solution {
    int helper(vector<int>&prices,int ind,int buy,vector<vector<int>>&dp){
        
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
        int sz=prices.size();
        vector<vector<int>>dp(sz+1,vector<int>(2,0));
        for(int ind=sz-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                   dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                   dp[ind][buy]=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};