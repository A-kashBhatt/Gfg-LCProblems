class Solution {
    bool isPalindrome(string s){
        int i=0,j=s.size()-1;
        while(j>i){
            if(s[i]!=s[j])return false;
            i++,j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1,check=0;
        while(j>i){
            if(s[i]==s[j]){
                i++,j--;
            }
            else{
                return (isPalindrome(s.substr(0,i)+s.substr(i+1))||
                        isPalindrome(s.substr(0,j)+s.substr(j+1)));
                    
            }
        }
        return true;
    }
};