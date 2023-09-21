class Solution {

public:
    bool isMatch(string s, string p) {
        int sz1=s.size(),sz2=p.size();
        vector<bool>prev(sz2+1,false),curr(sz2+1,false);
        prev[0]=true;
        bool extraChar=false;
        for(int j=1;j<=sz2;j++){
            if(p[j-1]!='*')extraChar=true;
            if(extraChar)break;
            prev[j]=true;
        }
        for(int i=1;i<=sz1;i++){
            curr[0]=false;
            for(int j=1;j<=sz2;j++){
                if((s[i-1]==p[j-1])||p[j-1]=='?')curr[j]=prev[j-1];
                else if(p[j-1]=='*'){
                    curr[j]=(prev[j] | curr[j-1]);
                }
                else curr[j]=false;
            }
            prev=curr;
        }
        return prev[sz2];
    }
};