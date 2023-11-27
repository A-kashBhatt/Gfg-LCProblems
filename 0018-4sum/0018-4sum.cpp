#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        vector<vector<int>>soln;
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                ll newTarget=(ll)target-nums[i]-nums[j];
                int k=j+1,l=sz-1;
                while(l>k){
                    if(nums[k]+nums[l]==newTarget){
                        soln.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int low=nums[k];
                        while(l>k && nums[k]==low)k++;
                        int high=nums[l];
                        while(l>k && nums[l]==high)l--;
                    }
                    else if(nums[k]+nums[l]<newTarget)k++;
                    else l--;
                }
                while(j+1<sz && nums[j]==nums[j+1])j++;
            }
            while(i+1<sz && nums[i]==nums[i+1])i++;
        }
        return soln;
    }
};