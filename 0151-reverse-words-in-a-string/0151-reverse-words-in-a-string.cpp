class Solution {
    void reverse(string &s){
        int i=0,j=s.size()-1;
        while(j>i){
            swap(s[i],s[j]);
            i++,j--;
        }
    }
public:
    string reverseWords(string s) {
         string soln="";
         int j=s.size()-1;
         while(j>=0){
             while(j>=0 && s[j]==' ')j--;
             string temp="";
             while(j>=0 && s[j]!=' '){
                 temp+=s[j];
                 j--;
             }
             reverse(temp);
             soln+=temp;
             if(temp!="")
             soln+=' ';
         }
        
        return soln.substr(0,soln.size()-1);
    }
};