class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                x=nums[i];
                cnt++;
                continue;
            }
            if(nums[i]==x)cnt++;
            else cnt--;
        }
        return x;
    }
};