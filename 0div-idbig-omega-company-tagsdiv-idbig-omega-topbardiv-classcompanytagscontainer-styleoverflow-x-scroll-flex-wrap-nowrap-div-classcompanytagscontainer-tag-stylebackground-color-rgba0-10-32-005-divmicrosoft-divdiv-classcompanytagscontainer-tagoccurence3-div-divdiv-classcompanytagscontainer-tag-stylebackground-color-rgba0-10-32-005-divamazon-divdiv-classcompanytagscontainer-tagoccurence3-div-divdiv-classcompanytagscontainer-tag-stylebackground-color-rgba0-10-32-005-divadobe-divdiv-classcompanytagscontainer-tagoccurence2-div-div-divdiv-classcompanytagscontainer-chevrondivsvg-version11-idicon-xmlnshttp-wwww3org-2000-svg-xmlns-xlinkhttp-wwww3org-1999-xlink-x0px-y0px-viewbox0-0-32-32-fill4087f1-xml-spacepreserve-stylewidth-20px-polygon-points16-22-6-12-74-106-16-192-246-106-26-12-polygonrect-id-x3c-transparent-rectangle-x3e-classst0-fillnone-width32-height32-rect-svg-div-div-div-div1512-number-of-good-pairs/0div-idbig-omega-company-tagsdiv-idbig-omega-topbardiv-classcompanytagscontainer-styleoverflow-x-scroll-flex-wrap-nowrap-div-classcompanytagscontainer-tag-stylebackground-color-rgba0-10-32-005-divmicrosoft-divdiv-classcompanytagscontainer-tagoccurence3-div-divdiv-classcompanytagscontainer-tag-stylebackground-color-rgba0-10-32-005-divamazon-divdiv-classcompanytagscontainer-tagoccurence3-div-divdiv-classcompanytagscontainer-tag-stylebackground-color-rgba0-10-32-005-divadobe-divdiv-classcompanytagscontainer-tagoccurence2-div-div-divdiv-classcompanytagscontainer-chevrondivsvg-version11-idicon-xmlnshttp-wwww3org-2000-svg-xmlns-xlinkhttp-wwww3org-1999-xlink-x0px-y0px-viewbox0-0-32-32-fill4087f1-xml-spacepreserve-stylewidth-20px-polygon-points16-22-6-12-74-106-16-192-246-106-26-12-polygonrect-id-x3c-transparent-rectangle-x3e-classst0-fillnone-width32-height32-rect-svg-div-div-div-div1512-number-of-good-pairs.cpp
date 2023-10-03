class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto it:nums)m[it]++;
        int cnt=0;
        for(auto it:m){
            int freq=it.second;
            cnt+=(freq*(freq-1)/2);
        }
        return cnt;
    }
};