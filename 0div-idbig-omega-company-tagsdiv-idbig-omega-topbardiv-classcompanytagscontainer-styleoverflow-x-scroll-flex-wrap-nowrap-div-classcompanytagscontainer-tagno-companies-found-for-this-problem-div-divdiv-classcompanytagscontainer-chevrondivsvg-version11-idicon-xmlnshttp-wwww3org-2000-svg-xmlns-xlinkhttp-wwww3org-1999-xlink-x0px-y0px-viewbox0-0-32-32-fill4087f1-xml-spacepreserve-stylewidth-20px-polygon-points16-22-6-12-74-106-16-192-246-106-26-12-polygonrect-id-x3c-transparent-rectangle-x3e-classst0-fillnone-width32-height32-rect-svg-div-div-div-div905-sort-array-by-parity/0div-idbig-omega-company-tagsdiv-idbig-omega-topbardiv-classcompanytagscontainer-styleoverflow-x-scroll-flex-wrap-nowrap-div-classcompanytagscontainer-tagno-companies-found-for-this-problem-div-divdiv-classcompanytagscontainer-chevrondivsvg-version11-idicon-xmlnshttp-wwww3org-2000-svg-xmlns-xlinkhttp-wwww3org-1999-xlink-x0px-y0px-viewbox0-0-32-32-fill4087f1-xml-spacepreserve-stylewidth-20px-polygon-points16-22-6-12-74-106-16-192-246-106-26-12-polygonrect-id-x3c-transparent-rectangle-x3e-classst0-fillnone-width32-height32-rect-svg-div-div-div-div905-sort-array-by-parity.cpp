class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,sz=nums.size(),j=sz-1;
        vector<int>soln(sz,0);
        for(auto it:nums){
            if(it%2){
                soln[j--]=it;
            }
            else{
                soln[i++]=it;
            }
        }
        return soln;
    }
};