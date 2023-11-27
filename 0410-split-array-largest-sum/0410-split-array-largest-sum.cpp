class Solution {
    bool isValid(vector<int>&A,int M,int m){
     int cnt=1,sum=0;
     int N=A.size();
     for(int i=0;i<N;i++){
         sum+=A[i];
         if(sum>m){
             cnt++;
             sum=A[i];
             if(cnt>M)return false;
         }
     }
     return true;
     }
public:
    int splitArray(vector<int>& nums, int k) {
        int s=*max_element(nums.begin(),nums.end());
        int e=accumulate(nums.begin(),nums.end(),0);
        int soln=-1;
        int n=nums.size();
        if(k>n)return -1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(isValid(nums,k,m)){
                soln=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return soln;
    }
};