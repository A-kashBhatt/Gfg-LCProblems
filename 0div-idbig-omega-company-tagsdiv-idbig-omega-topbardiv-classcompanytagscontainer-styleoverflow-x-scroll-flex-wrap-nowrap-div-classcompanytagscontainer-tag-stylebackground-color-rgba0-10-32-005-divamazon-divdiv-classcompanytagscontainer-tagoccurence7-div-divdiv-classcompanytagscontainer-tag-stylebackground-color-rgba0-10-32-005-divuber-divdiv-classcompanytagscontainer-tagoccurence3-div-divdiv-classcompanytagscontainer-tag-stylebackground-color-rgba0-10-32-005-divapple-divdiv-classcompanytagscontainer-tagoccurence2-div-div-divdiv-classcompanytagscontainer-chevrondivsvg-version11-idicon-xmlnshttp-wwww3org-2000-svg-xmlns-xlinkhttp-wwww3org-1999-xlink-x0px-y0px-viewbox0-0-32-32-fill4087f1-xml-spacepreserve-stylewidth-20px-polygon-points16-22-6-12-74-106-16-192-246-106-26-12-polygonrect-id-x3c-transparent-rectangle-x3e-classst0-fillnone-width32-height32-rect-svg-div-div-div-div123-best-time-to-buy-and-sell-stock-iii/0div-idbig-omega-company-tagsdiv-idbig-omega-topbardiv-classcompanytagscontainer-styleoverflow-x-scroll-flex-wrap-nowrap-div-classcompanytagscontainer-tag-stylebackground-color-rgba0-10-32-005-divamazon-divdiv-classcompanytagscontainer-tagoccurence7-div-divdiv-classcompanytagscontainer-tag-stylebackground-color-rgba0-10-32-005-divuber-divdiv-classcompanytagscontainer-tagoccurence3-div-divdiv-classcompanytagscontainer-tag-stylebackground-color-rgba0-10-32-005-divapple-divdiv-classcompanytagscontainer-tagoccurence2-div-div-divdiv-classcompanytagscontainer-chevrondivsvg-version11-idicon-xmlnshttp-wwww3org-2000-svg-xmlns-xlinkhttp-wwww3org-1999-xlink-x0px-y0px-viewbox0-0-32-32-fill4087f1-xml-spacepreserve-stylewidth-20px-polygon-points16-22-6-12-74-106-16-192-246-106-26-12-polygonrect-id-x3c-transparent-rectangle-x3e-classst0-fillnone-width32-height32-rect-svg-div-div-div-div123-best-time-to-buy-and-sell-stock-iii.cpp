//tabulation with further space optimized
class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        vector<vector<int>>curr(2,vector<int>(3,0)),ahead(2,vector<int>(3,0));
        for(int ind=sz-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                for(int trades=2;trades>0;trades--){
                    if(buy){
                       curr[buy][trades]=max(-prices[ind]+ ahead[0][trades], ahead[1][trades]);
            }
                    
                    else{
                        curr[buy][trades]= max(prices[ind]+ ahead[1][trades-1], ahead[0][trades]);
            }
                    }
                }
                ahead=curr;
            }
        
        return ahead[1][2];
    }
};