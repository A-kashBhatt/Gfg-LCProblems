class Solution {
public:
    int numDistinct(string str, string sub) {
        int sz1=str.size(),sz2=sub.size();
	if(sz2>sz1)return 0;
	vector<double>prev(sz2+1,0);
	prev[0]=1;
	for(int i=1;i<=sz1;i++){
		for(int j=sz2;j>=1;j--){
			double take=0,notTake=0;
	        if(str[i-1]==sub[j-1])take=prev[j-1];
            notTake=prev[j];
	        prev[j]=take+notTake;
		}
	}
	return (int)prev[sz2];
    }
};