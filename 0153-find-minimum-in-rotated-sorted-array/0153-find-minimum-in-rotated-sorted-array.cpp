class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,ans=INT_MAX;
        while(e>=s){
            int m=s+(e-s)/2;
            if(nums[m]>nums[e]){
                s=m+1;
                ans=min(nums[0],ans);
            }
            else{
                e=m-1;
                ans=min(nums[m],ans);
            }
        }
        return ans;
    }
};