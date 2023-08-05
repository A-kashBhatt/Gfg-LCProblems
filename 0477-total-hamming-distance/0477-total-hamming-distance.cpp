class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int>ones(32,0);
        int sz=nums.size();
        for(int i=0;i<32;i++){
            int mask=(1<<i);
            for(int j=0;j<sz;j++){
                if(nums[j]&mask)ones[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            int a=ones[i],b=sz-a;
            ans+=(a*b);
        }
        return ans;
    }
};