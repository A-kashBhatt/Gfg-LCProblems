class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      if(nums.size()==1)return 0;
      int s=0,e=nums.size()-1;
       while(e>=s){
           int m=s+(e-s)/2;
           if(m==0){
               return nums[0]>nums[1]?0:1;
           }
           if(m==nums.size()-1){
               return nums[nums.size()-1]>nums[nums.size()-2]?nums.size()-1:nums.size()-2;
           }
           
           if(nums[m]>nums[m+1] && nums[m]>nums[m-1])return m;
           
           else if(nums[m]<nums[m-1]){
               e=m-1;
           }
           else s=m+1;    
       }
       return 1;
      
    }
};