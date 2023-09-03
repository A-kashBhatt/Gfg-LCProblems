class Solution {
    void helper(vector<int>& nums,int i,vector<vector<int>>&soln){
        if(i==nums.size())soln.push_back(nums);
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            helper(nums,i+1,soln);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>soln;
        helper(nums,0,soln);
        return soln;
    }
};