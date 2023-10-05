class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>soln;
        unordered_map<int,int>m;
        int sz=nums.size();
        for(auto it:nums)m[it]++;
        for (auto it:m)if(it.second>sz/3)soln.push_back(it.first);
        return soln;
    }
};