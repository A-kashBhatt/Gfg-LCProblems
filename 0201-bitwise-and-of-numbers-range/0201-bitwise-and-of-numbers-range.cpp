class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(int i=30;i>=0;i--){
            int mask=(1<<i);
            int leftB=  (left&mask);
            int rightB= (right&mask);
            if(leftB!=rightB)break;
            leftB!=0?ans+=mask:ans+=0;
        }
        return ans;
    }
};