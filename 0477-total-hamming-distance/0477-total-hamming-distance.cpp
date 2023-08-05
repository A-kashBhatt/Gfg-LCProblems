class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // vector<int>ones(32,0);
        int sz=nums.size(),ans=0;
        for(int i=0;i<32;i++){
            int mask=(1<<i);
            int ones=0;
            for(int j=0;j<sz;j++){
                if(nums[j]&mask)ones++;
            }
            int a=ones,b=sz-ones;
            ans+=(a*b);
        }
        return ans;
    }
};