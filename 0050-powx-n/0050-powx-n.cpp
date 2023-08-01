class Solution {
public:
    double myPow(double x, int n) {
        double ans=0;
        if(n==0)return 1;
        if(n<0){
            if(n==INT_MIN) return myPow(x*x,n/2);
            return 1.0/myPow(x,abs(n));
        }
        else{
            if(n%2){
                return 1.0*x*myPow(x*x,(n-1)/2);
            }
            else{
                return 1.0*myPow(x*x,n/2);
            }
        }
    }
};