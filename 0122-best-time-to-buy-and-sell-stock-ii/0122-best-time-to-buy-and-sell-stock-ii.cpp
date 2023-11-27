//space optimization
class Solution { 
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        int currBuy=0,currNotBuy=0,aheadBuy=0,aheadNotBuy=0;
        for(int ind=sz-1;ind>=0;ind--){
            currBuy=max(-prices[ind]+aheadNotBuy,aheadBuy);
            currNotBuy=max(prices[ind]+aheadBuy,aheadNotBuy);
            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
       }
        return currBuy;
    }
};