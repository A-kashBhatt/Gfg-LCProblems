class Solution {
    int helper(vector<int>& nums,int s,int e){
        
        int m=s+(e-s)/2;
        if(m==0)return min(nums[0],nums[1]);
        if(m==nums.size()-1)return min(nums[nums.size()-1],nums[nums.size()-2]);
        if(nums[m]<nums[m+1] && nums[m]<nums[m-1])return nums[m];
        else if(nums[m]>nums[e]) return helper(nums,m+1,e);
        else return helper(nums,s,m-1);
    }
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return helper(nums,0,nums.size()-1);
    }
};