class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int sz=nums.size();
        if(sz<3)return false;
        vector<int>mini;
        mini.push_back(nums[0]);
        for(int j=1;j<sz;j++){
            mini.push_back(min(mini[j-1],nums[j]));
        }
        stack<int>s;
        for(int k=sz-1;k>=1;k--){
           while(s.size()>0 && s.top()<=mini[k-1])s.pop();
           if(s.size() && mini[k-1]<s.top() && s.top()<nums[k])return true;
           s.push(nums[k]);
        }
        return false;
    }
};