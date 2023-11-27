class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxAns=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxAns=max(sum,maxAns);
            if(sum<0)sum=0;
        }
        return maxAns;
    }
};