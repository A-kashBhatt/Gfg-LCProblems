class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int sz=nums.size();
        bool inc=nums[0]>nums[sz-1]?false:true;
        for(int i=0;i<sz-1;i++){
            if(inc && nums[i]>nums[i+1])return false;
            if(!inc && nums[i]<nums[i+1])return false;
        }
        return true;
    }
};