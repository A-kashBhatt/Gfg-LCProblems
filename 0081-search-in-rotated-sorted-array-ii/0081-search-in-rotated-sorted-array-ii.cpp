class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        while(e>=s){
            int m=s+(e-s)/2;
            if(nums[m]==target)return true;
            if(nums[m]==nums[s] && nums[m]==nums[e]){
                s++;
                e--;
                continue;
            }
            if(nums[m]==target)return true;
            
            if(nums[m]>nums[e]){
                if(nums[s]<=target && nums[m]>=target){
                    e=m-1;
                }
                else{
                    s=m+1;
                }
            }
            else{
                if(nums[m]<=target && nums[e]>=target){
                    s=m+1;
                }
                else{
                    e=m-1;
                }
            }
            
        }
        return false;;
    }
};