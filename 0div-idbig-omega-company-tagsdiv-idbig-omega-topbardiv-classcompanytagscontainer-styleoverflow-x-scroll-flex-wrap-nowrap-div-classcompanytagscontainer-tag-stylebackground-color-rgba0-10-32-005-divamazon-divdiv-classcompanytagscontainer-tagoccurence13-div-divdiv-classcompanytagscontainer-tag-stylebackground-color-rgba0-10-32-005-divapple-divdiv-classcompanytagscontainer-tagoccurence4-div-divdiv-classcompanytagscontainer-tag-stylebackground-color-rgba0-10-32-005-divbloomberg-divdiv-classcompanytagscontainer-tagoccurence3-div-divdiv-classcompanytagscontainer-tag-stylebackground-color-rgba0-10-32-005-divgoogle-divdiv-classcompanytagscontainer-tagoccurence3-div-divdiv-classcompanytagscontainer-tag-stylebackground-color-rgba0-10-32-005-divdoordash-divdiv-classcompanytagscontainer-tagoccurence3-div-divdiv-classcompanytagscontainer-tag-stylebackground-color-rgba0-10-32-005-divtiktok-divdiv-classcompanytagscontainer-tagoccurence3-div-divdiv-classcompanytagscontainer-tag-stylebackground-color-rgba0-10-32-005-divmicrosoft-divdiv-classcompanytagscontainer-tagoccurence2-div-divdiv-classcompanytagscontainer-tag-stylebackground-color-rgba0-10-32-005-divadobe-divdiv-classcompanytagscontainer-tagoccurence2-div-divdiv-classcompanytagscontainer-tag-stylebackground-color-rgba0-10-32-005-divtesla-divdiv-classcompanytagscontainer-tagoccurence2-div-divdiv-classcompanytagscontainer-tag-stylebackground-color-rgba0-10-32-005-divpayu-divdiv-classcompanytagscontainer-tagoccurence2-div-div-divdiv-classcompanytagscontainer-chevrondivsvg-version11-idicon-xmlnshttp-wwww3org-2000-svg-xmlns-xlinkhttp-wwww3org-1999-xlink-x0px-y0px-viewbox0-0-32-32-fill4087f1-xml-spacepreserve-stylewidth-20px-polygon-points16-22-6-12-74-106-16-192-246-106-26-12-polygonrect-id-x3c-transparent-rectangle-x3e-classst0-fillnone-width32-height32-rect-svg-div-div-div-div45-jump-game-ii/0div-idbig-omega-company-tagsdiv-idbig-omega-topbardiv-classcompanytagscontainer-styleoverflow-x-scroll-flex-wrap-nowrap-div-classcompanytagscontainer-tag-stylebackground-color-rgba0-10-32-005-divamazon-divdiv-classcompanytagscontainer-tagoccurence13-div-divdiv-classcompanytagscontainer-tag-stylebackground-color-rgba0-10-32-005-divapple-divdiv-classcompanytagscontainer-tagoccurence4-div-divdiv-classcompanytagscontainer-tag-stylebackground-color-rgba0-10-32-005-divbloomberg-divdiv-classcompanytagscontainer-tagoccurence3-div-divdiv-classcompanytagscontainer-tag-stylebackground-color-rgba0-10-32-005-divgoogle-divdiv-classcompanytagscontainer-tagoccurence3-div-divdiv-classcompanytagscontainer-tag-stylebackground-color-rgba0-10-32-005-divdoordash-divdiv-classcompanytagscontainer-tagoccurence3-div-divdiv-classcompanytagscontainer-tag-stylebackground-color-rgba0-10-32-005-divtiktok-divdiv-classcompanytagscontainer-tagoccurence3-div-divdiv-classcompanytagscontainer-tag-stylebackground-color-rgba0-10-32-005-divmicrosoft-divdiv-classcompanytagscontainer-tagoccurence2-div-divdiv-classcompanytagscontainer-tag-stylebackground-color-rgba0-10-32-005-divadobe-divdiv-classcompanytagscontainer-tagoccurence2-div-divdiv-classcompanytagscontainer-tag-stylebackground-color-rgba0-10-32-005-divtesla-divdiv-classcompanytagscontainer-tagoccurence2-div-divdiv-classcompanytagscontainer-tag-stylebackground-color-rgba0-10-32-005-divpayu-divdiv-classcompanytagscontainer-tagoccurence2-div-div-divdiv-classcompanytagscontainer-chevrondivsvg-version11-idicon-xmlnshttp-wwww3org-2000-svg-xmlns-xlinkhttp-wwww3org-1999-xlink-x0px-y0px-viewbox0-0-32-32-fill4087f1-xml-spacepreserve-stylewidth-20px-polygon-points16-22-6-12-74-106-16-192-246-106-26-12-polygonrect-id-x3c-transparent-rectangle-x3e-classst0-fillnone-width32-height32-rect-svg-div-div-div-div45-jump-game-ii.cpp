class Solution {
public:
    int jump(vector<int>& nums) {
        int curr=0,minJump=0;
        if(nums.size()==1)return 0;
        while(1){
            int maxJump=nums[curr],maxReach=curr+maxJump,newStart=curr;
            if(maxReach>=nums.size()-1)return minJump+1;
            for(int i=curr;i<=curr+maxJump;i++){
                if(i+nums[i]>=maxReach){
                    newStart=i;
                    maxReach=i+nums[i];
                }
            }
            curr=newStart;
            minJump++;
        }
        return minJump;
    }
};