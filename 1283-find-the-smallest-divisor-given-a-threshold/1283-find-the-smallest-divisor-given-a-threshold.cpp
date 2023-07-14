class Solution {
    bool isValid(vector<int>& nums, int threshold,int m){
        int x=0;
        for(int i=0;i<nums.size();i++){
            x+=(ceil(1.0*nums[i]/m));
            if(x>threshold)return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1,e=*max_element(nums.begin(),nums.end());
        int soln=e;
        while(e>=s){
            int m=s+(e-s)/2;
            if(isValid(nums,threshold,m)){
                e=m-1;
                soln=m;
            }
            else s=m+1;
        }
        return soln;
    }
};