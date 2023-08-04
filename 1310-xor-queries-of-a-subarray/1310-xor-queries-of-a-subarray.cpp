class Solution {
public:
    //PreComputing
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int curr=arr[0],sz=arr.size();
        vector<int>store;
        store.push_back(curr);
        for(int i=1;i<sz;i++){
            curr=(curr^arr[i]);
            store.push_back(curr);
        }
        vector<int>soln;
        for(auto it:queries){
            int a=it[0],b=it[1];
            soln.push_back(store[a]^store[b]^arr[a]);
        }
        return soln;
        
    }
};