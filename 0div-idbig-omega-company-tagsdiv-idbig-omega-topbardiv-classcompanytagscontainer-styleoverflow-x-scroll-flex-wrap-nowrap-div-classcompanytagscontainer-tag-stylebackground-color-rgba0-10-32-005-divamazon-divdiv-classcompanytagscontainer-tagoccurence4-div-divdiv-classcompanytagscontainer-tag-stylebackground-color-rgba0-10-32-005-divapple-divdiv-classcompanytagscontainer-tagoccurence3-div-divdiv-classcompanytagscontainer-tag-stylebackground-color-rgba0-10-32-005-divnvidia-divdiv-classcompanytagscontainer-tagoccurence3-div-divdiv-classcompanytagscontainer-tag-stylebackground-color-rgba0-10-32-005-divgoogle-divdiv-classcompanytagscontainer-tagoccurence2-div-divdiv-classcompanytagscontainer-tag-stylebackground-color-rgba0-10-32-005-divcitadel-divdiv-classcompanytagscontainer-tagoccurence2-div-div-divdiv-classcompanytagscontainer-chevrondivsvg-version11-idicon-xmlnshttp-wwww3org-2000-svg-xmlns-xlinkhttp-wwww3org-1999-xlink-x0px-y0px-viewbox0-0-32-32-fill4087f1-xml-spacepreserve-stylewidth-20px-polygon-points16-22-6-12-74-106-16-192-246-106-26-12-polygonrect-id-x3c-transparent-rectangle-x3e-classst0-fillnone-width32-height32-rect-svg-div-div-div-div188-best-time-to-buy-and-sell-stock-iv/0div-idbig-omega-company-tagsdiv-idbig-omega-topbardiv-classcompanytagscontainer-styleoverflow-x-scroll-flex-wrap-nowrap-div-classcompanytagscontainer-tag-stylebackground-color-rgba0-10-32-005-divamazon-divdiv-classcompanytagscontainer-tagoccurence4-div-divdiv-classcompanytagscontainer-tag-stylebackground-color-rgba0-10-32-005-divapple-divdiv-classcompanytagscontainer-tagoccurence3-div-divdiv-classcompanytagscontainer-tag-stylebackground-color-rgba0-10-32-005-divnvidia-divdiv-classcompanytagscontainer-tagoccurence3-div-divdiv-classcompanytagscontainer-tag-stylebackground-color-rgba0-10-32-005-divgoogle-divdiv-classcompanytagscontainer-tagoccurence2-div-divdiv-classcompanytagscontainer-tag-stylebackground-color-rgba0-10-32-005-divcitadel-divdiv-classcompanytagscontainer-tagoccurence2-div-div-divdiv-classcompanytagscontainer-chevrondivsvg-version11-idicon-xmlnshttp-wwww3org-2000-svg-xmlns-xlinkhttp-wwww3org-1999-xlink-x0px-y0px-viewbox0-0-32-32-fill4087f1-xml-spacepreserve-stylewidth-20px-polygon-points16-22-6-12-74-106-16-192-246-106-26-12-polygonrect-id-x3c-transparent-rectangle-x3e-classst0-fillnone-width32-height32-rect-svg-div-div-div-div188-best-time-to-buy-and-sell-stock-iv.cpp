class Solution {
    int helper(vector<int>&prices,int ind,int buy,int n,int trades,
              vector<vector<vector<int>>>&dp){
            if(ind==n || trades==0)return 0;
            if(dp[ind][buy][trades]!=-1)return dp[ind][buy][trades];
            if(buy){
              return dp[ind][buy][trades]=max(-prices[ind]+ helper(prices,ind+1,0,n,trades,dp),helper(prices,ind+1,1,n,trades,dp));
            }
            else{
              return dp[ind][buy][trades]= max(prices[ind]+ helper(prices,ind+1,1,n,trades-1,dp), helper(prices,ind+1,0,n,trades,dp));
            }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int sz=prices.size();
        vector<vector<vector<int>>>dp(sz,vector<vector<int>>(2,vector<int>    (k+1,-1)));
        return helper(prices,0,1,sz,k,dp);
    }
};