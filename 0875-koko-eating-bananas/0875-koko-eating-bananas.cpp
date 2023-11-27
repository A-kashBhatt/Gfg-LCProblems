class Solution {
    bool isValid(vector<int>& piles, int h,int m){
        int time=0;
        for(int i=0;i<piles.size();i++){
            time+=(ceil(1.0*piles[i]/m));
            if(time>h)return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=*max_element(piles.begin(),piles.end());
        int soln=e;
        while(e>=s){
            int m=s+(e-s)/2;
            if(isValid(piles,h,m)){
                e=m-1;
                soln=m;
            }
            else s=m+1;
        }
        return soln;
    }
};