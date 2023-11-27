
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long value=0;
        for(auto it:nums)(value=value xor it);
        long int x=value-(value&(value-1));
        int bit=log2(x);
        int value1=0;
        for(auto it:nums){
            if(it&(1<<bit))(value1=value1^it);
        }
        vector<int>soln;
        soln.push_back(value1);
        soln.push_back(value1^value);
        return soln;
    }
};