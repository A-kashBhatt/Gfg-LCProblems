class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        vector<vector<int>>soln;
        for(int i=0;i<sz;i++){
            int j=i+1,k=sz-1;
            while(k>j){
                if(nums[i]+nums[j]+nums[k]==0){
                    soln.push_back({nums[i],nums[j],nums[k]});
                    int low=nums[j];
                    while(j<k && nums[j]==low)j++;
                    int high=nums[k];
                    while(k<j && nums[k]==high)k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0)k--;
                else j++;
            }
            while(i+1<sz && nums[i]==nums[i+1])i++;
        }
        return soln;
        
    }
};