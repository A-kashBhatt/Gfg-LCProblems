class Solution {
public:
    string smallestSubsequence(string s) {
        stack<int>st;
        vector<int>lastInd(26,-1);
        vector<bool>seen(26,false);
        int sz=s.size();
        for(int i=0;i<sz;i++)lastInd[s[i]-'a']=i;
        for(int i=0;i<sz;i++){
            char c=s[i];
            if(seen[c-'a'])continue;
            while(st.size()  && c<st.top() && lastInd[st.top()-'a']>i){
                seen[st.top()-'a']=false;
                st.pop();
            }
            seen[c-'a']=true;
            st.push(c);
        }
        string soln;
        while(st.size()){
            soln+=st.top();
            st.pop();
        }
        reverse(soln.begin(),soln.end());
        return soln;
    }
};