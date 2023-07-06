class Solution {
    int helper(vector<int>& nums,int s,int e){
        int n=nums.size();
        int m=s+(e-s)/2;
        if(m==0)return nums[0]>nums[1]?1:0;
        if(m==n-1)return nums[n-1]>nums[n-2]?(n-2):(n-1);
        if(nums[m]<nums[m+1] && nums[m]<nums[m-1])return m;
        else if(nums[m]>nums[e]) return helper(nums,m+1,e);
        else return helper(nums,s,m-1);
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1) return nums[0]==target ? 0:-1;
        int index=helper(nums,0,n-1);
        if(index==0 || (target<=nums[n-1])){
            if(binary_search(nums.begin()+index,nums.end(),target)){
            return lower_bound(nums.begin()+index,nums.end(),target)-nums.begin();
            }
            else return -1;
        }
        else{
            if(binary_search(nums.begin(),nums.begin()+index,target)){
            return lower_bound(nums.begin(),nums.begin()+index,target)-nums.begin();
            }
            else return -1;
        }
    }
};