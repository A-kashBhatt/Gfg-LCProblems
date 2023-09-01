class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sz=customers.size();
        int ans=0;
        for(int i=0;i<sz;i++){
            if(grumpy[i]==0)ans+=customers[i];
        }
        int i=0,j=0,maxi=INT_MIN,currValue=0;
        while(j<sz && i<sz){
            if(grumpy[j])currValue+=customers[j];
            if(j-i+1==minutes){
                maxi=max(maxi,currValue);
                if(grumpy[i])currValue-=customers[i];
                i++;
            }
            j++;
        }
        return ans+maxi;
    }
};