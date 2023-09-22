class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,sz1=s.size(),sz2=t.size();
        if(sz1==sz2 && sz1==0)return true;
        if(sz2<sz1)return false;
        for(;i<sz2;i++){
            if(t[i]==s[j])j++;
            if(j==sz1)return true;
        }
        return false;
    }
};