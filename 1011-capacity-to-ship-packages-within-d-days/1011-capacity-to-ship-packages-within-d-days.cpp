class Solution {
    bool isValid(vector<int>& weights, int days,int m){
        int sum=0,x=1;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>m){
                x++;
                sum=weights[i];
                if(x>days)return false;
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);
        int soln=e;
        int n=weights.size();
        while(s<=e){
            int m=s+(e-s)/2;
            if(isValid(weights,days,m)){
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