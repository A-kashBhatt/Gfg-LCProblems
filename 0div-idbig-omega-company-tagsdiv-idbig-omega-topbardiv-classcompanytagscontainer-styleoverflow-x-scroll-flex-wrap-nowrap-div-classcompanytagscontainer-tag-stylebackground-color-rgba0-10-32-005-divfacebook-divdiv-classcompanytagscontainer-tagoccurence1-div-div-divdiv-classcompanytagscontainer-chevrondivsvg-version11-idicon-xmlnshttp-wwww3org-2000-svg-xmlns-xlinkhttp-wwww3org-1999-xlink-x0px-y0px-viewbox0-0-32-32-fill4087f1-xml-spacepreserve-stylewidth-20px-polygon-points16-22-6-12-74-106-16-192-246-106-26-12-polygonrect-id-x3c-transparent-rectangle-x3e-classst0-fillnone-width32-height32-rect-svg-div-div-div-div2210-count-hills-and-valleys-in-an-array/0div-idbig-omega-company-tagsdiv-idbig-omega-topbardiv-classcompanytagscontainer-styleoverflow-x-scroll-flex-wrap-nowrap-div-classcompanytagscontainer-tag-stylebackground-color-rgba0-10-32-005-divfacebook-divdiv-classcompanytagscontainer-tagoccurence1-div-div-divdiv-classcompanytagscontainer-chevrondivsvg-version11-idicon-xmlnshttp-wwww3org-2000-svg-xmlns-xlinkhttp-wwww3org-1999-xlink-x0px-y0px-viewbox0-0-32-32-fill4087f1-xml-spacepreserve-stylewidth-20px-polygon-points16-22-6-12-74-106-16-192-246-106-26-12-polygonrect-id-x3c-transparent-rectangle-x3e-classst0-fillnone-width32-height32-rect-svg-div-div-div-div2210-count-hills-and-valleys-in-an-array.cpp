class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt=0,sz=nums.size();
        for(int i=1;i<sz-1;i++){
            int li=i-1,ri=i+1;
            while(li>=0 && nums[li]==nums[i])li--;
            while(ri<sz && nums[ri]==nums[i])ri++;
            int left=li<0?-1:nums[li];
            int right=ri==sz?-1:nums[ri];
            if(left==-1 || right==-1)continue;
            if(left>nums[i] && right>nums[i])cnt++;
            if(left<nums[i] && right<nums[i])cnt++;
            int j=i+1;
            while(j<sz && nums[j]==nums[i])j++;
            i=j-1;
        }
        return cnt;
    }
};