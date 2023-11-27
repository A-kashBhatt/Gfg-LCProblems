class Solution {
    int findFirstOccurence(vector<int>& nums, int target,int s,int e){
      if(nums.size()==0){
          return -1;
      }
      if(s>e){
         if(s>=0 && s<nums.size() && nums[s]==target){
             return s;
         }
         return -1;
      }
      int mid=(s+e)/2;
      if(nums[mid]>=target){
          return findFirstOccurence(nums,target,s,mid-1);
      }
      else{
          return findFirstOccurence(nums,target,mid+1,e);
          
      }
    }

    int findLastOccurence(vector<int>& nums, int target,int s,int e){
      if(nums.size()==0){
          return -1;
      }
      if(s>e){
         if(e>=0 && e<nums.size() && nums[e]==target){
             return e;
         }
         return -1;
      }
      int mid=(s+e)/2;
      if(nums[mid]<=target){
          return findLastOccurence(nums,target,mid+1,e);
      }
      else{
          return findLastOccurence(nums,target,s,mid-1);
      }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findFirstOccurence(nums,target,0,nums.size()-1);
        int last=findLastOccurence(nums,target,0,nums.size()-1);
        vector<int>soln={first,last};
        return soln;
    }
};