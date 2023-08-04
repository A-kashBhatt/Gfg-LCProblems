class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        int sz=nums.size();
        for(int i=0;i<sz;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0,j=sz-1;
        while(j>i){
            if(v[i].first+v[j].first==target)return {v[i].second,v[j].second};
            else if(v[i].first+v[j].first>target)j--;
            else i++;
        }
        return {};
    }
};