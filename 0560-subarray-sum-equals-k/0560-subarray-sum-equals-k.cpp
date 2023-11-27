class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int sz=nums.size(),sum=0,ans=0;
        m[0]=1;
        for(int i=0;i<sz;i++){
            sum+=nums[i];
            if(m.count(sum-k))ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
            
    }
};