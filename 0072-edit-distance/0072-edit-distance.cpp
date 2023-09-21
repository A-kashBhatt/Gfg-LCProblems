//tabulated and space optimized
class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1=word1.size(),sz2=word2.size(),prevVal,currVal;
        vector<int>prev(sz2+1,0);
        for(int i=0;i<=sz2;i++)prev[i]=i;
        for(int i=1;i<=sz1;i++){
            prevVal=prev[0];
            prev[0]=i;
            for(int j=1;j<=sz2;j++){
                currVal=prev[j];
                if(word1[i-1]==word2[j-1])prev[j]=prevVal;
                else{
                    int replace=1+prevVal;
                    int insert=1+prev[j-1];
                    int remove=1+prev[j];
                    prev[j]=min(replace,min(insert,remove));
                }
                prevVal=currVal;
            }
        }
        return prev[sz2];
    }
};