class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int sz=strs.size(),i=0;
        char a,b;
        string ans="";
        if(sz==0)return "";
        while(1){
            if(strs[0].size()>i)a=strs[0][i];
            else return ans;
            if(strs[sz-1].size()>i)b=strs[sz-1][i];
            else return ans;
            if(a==b)ans+=strs[0][i++];
            else return ans;
        }
        return ans;
    }
};