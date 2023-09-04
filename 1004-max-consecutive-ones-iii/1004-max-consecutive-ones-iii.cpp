class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,cnt=0,ans=0,sz=nums.size();
        while(j<sz){
        
            if(nums[j]==0)cnt++;
            while(i<sz && cnt>k){
                   if(nums[i]==0)cnt--;
                   i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};