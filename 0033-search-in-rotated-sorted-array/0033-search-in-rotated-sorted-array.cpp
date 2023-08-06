class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0,sz=nums.size(),e=sz-1;
        while(e>=s){
            int mid=s+(e-s)/2;
            if(nums[mid]==target)return  mid;
            if(nums[s]<=nums[mid]){
                if(target>=nums[s] && target<nums[mid])e=mid-1;
                else s=mid+1;
            }
            else{
                if(target>nums[mid] && target<=nums[e])s=mid+1;
                else e=mid-1;
            }
        }
        return -1;
    }
};