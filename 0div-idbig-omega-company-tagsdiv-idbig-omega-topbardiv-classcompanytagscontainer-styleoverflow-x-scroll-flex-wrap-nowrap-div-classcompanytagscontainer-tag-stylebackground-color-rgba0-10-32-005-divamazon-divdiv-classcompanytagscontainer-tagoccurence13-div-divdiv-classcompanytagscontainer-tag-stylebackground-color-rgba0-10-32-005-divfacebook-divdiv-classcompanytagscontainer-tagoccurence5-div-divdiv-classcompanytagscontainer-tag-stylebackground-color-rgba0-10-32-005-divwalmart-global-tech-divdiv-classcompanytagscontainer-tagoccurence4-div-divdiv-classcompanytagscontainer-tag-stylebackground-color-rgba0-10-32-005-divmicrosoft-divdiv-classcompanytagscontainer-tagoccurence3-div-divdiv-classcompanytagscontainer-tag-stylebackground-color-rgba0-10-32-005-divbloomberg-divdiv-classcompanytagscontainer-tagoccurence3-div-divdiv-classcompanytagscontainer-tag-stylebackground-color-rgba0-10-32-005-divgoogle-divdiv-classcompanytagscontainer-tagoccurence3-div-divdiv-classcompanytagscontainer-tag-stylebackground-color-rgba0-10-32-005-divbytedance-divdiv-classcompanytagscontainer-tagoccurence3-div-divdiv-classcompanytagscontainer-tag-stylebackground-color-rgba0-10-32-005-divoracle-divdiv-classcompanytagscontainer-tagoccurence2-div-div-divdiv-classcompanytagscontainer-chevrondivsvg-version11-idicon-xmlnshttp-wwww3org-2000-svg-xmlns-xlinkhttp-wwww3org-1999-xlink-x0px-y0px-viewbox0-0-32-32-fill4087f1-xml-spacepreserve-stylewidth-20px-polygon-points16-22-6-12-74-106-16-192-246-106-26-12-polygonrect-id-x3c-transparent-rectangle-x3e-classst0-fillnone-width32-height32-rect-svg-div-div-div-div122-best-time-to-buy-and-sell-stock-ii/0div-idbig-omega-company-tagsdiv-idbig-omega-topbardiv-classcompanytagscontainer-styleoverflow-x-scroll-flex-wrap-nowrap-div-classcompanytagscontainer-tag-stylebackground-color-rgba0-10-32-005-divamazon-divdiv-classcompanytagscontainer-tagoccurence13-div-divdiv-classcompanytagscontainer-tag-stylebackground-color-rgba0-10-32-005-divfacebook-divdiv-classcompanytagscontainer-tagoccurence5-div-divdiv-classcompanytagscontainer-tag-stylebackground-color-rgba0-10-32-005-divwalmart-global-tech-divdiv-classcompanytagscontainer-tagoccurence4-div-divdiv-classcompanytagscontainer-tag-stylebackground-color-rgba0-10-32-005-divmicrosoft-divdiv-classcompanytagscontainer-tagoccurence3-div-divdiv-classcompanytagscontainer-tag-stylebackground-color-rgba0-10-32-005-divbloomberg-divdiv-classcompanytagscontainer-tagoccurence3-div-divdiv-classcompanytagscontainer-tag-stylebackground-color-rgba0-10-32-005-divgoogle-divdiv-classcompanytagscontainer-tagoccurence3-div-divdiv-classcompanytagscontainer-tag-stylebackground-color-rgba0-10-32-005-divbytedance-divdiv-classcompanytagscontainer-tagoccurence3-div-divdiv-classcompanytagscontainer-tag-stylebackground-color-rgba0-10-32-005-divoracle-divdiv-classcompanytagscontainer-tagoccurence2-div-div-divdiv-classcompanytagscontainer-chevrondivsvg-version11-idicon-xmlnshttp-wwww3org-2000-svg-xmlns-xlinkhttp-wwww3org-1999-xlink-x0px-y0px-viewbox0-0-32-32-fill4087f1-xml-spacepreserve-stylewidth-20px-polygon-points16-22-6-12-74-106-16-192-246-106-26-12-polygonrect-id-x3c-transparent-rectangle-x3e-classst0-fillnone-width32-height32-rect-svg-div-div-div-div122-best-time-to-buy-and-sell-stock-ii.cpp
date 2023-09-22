//space optimization
class Solution { 
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        vector<int>prev(2,0),curr(2,0);
        for(int ind=sz-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                   curr[buy]=max(-prices[ind]+prev[0],prev[1]);
                }
                else{
                   curr[buy]=max(prices[ind]+prev[1],prev[0]);
                }
            }
            prev=curr;
        }
        
        return prev[1];
    }
};