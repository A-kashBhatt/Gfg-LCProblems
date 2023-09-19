class Solution {
    bool helper(vector<int>& matchsticks,vector<int>&sides,int i,int target){
            if(sides[0]==target && sides[1]==target && sides[2]==target &&                      sides[3]==target){
                return true;
            }
        for(auto it:sides)if(it>target)return false;
        if(i<0)return false;
        for(int j=0;j<4;j++){
            // int k=j-1;
            // while(k>=0){
            //     if(sides[k]==sides[j])break;
            //     k--;
            // }
            // if(k!=-1)continue;
            sides[j]+=matchsticks[i];
            if(helper(matchsticks,sides,i-1,target))return true;
            sides[j]-=matchsticks[i];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
         int sz=matchsticks.size();
         int totalSum=accumulate(matchsticks.begin(),matchsticks.end(),0);
         if(totalSum%4)return false;
         int target=totalSum/4;
         sort(matchsticks.begin(),matchsticks.end());
         if(matchsticks[sz-1]>target)return false;
         vector<int>sides(4,0);
         return helper(matchsticks,sides,sz-1,target);    
    }
};