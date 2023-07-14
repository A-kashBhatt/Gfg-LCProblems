class Solution {
    bool isValid(vector<int>& bloomDay, int m, int k,int mid){
        int bq=0,curr=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                curr++;
                if(curr==k){
                bq++;
                curr=0;
               }
                if(bq>=m)return true;
            }
            else curr=0;
            
                
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k)return -1;
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int soln=e;
        while(e>=s){
            int mid=s+(e-s)/2;
            if(isValid(bloomDay,m,k,mid)){
                soln=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return soln;
    }
};