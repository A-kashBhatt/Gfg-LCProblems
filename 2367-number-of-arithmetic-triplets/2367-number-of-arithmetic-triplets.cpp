class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int>m;
        for(auto it:nums)m[it]++;
        int sz=nums.size();
        int cnt=0;
        for(int i=0;i<sz;i++){
            m.erase(nums[i]);
            if(m.count(nums[i]+diff) && m.count(nums[i]+2*diff))cnt++;
            if(m.count(nums[i]+diff) && m.count(nums[i]-diff))cnt++;
            if(m.count(nums[i]-diff) && m.count(nums[i]-2*diff))cnt++;
        }
        return cnt;
    }
};