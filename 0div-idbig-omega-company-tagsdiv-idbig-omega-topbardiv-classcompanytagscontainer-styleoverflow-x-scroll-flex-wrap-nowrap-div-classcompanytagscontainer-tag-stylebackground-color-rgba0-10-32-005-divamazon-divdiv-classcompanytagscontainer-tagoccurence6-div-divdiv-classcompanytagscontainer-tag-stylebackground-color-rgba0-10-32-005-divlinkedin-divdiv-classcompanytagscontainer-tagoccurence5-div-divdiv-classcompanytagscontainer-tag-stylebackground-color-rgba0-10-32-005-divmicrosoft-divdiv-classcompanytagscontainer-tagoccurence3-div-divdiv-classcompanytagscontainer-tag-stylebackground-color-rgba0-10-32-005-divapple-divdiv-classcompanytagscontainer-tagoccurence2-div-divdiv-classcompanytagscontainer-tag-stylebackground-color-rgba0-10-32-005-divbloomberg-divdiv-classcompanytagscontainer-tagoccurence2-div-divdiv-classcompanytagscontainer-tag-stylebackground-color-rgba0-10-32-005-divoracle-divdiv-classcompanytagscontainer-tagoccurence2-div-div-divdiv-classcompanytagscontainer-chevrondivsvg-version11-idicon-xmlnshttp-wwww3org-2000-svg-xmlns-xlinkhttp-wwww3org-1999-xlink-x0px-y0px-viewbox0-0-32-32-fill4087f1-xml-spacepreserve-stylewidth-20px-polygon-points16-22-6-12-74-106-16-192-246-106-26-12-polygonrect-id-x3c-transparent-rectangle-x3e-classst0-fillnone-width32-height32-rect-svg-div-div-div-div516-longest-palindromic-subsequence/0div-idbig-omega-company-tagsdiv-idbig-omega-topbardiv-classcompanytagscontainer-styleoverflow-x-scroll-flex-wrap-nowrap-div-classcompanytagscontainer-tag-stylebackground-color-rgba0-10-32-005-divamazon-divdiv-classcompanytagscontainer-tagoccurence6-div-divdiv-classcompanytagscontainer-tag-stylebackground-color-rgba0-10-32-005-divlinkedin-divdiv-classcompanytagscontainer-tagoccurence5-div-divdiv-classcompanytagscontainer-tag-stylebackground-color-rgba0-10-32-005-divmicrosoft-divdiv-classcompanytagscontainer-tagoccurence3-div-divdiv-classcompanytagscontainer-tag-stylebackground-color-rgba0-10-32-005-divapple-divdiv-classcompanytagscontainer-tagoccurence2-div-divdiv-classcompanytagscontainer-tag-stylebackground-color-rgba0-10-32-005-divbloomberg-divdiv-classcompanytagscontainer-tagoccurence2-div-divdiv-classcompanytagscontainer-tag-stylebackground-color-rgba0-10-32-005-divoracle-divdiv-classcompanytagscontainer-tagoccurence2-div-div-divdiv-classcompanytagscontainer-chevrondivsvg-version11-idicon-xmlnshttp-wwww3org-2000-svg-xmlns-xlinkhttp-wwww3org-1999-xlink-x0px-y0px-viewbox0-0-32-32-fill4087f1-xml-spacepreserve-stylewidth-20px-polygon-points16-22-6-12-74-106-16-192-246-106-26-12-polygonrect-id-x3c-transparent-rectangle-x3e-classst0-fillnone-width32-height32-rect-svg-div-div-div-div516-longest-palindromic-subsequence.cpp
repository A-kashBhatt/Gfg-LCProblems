class Solution {
int lcs(string s, string t)
{   
	int sz1=s.size(),sz2=t.size(),x=0,prevVar=0,currVar=0;
	vector<int>prev(sz2,0); 
	for(int i=0;i<sz1;i++){
		for(int j=0;j<sz2;j++){
			currVar=prev[j];
			if(s[i]==t[j]){
				if(j-1>=0)prev[j]=1+prevVar;
				else prev[j]=1;
			}
			else{
				int a=0;
				if(j-1>=0)a=prev[j-1];
				prev[j]=max(a,prev[j]);
			}
			prevVar=currVar;
		}
		prevVar=0;
	}
	return prev[sz2-1];
}
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
};