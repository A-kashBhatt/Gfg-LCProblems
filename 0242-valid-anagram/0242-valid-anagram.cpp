class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size())return false;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        int sz=s.size();
        for(int i=0;i<sz;i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(int i=0;i<sz;i++){
            if(m1[s[i]]!=m2[s[i]])return false;
        }
        return true;
    }
};