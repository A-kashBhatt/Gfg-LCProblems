class Solution {

public:
    bool isMatch(string s, string p) {
        int sz1=s.size(),sz2=p.size();
        vector<bool>prev(sz2+1,false);
        prev[0]=true;
        bool extraChar=false,prevVal=false,currVal=false;
        for(int j=1;j<=sz2;j++){
            if(p[j-1]!='*')extraChar=true;
            if(extraChar)break;
            prev[j]=true;
        }
        for(int i=1;i<=sz1;i++){
            prevVal=prev[0];
            prev[0]=false;
            for(int j=1;j<=sz2;j++){
                currVal=prev[j];
                if((s[i-1]==p[j-1])||p[j-1]=='?')prev[j]=prevVal;
                else if(p[j-1]=='*'){
                    prev[j]=(prev[j] | prev[j-1]);
                }
                else prev[j]=false;
                prevVal=currVal;
            }
        }
        return prev[sz2];
    }
};