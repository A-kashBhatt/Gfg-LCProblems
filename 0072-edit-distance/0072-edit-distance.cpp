//tabulated and space optimized
class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1=word1.size(),sz2=word2.size();
        vector<int>prev(sz2+1,0),curr(sz2+1,0);
        for(int i=0;i<=sz2;i++)prev[i]=i;
        for(int i=1;i<=sz1;i++){
            curr[0]=i;
            for(int j=1;j<=sz2;j++){
                if(word1[i-1]==word2[j-1])curr[j]=prev[j-1];
                else{
                    int replace=1+prev[j-1];
                    int insert=1+curr[j-1];
                    int remove=1+prev[j];
                    curr[j]=min(replace,min(insert,remove));
                }
            }
            prev=curr;
        }
        return prev[sz2];
    }
};