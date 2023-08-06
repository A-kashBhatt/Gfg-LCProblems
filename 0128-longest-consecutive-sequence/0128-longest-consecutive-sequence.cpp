class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        int sz=nums.size();
        for(auto it:nums)m[it]++;
        int ans=0;
        for(int i=0;i<sz;i++){
            if(m.count(nums[i]-1)==0){
                int temp=1;
                while(1){
                    if(m.count(nums[i]+temp)==0){
                        ans=max(ans,temp);
                        break;
                    }
                    temp++;
                }
            }
        
        }
        return ans;
    }
};