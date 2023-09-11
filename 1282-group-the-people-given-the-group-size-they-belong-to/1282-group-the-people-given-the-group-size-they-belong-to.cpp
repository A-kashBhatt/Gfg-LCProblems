class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>soln;
        map<int,vector<int>>m;
        int sz=groupSizes.size();
        for(int i=0;i<sz;i++)m[groupSizes[i]].push_back(i);
        for(auto it:m){
            vector<int>curr=it.second;
            int s=it.first,freq=curr.size();
            while(freq){
                vector<int>v;
                int j=0;
                for(int i=0;i<s;i++){
                    v.push_back(curr[j++]);
                    freq--;
                }
                soln.push_back(v);
            }
        }
        return soln;
    }
};