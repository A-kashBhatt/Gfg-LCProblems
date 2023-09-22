//tabulation
class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=sz-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                for(int trades=2;trades>0;trades--){
                    if(buy){
                       dp[ind][buy][trades]=max(-prices[ind]+ dp[ind+1][0][trades], dp[ind+1][1][trades]);
            }
                    
                    else{
                        dp[ind][buy][trades]= max(prices[ind]+ dp[ind+1][1][trades-1], dp[ind+1][0][trades]);
            }
                    }
                }
            }
        
        return dp[0][1][2];
    }
};