class Solution {
    string findLCS(int n, int m,string &s, string &t){
	int sz1=n,sz2=m;
	vector<vector<int>>dp(sz1,vector<int>(sz2,0)); 
	for(int i=0;i<sz1;i++){
		for(int j=0;j<sz2;j++){
			if(s[i]==t[j]){
				if(i-1>=0 && j-1>=0)dp[i][j]=1+dp[i-1][j-1];
				else dp[i][j]=1;
			}
			else{
				int a=0,b=0;
				if(i-1>=0)a=dp[i-1][j];
				if(j-1>=0)b=dp[i][j-1];
				dp[i][j]=max(a,b);
			}
		}
	}
	int x=sz1-1,y=sz2-1;
	string soln="";
	while(x>=0 && y>=0){
          if(s[x]==t[y]){
			  soln=s[x]+soln;
			  x--,y--;
		  }
          else{
			  if(x-1>=0 && y-1>=0){
                 if(dp[x-1][y]>dp[x][y-1]){
					 x--;
				 }
				 else y--;
			  }
			  else{
				  if(x-1>=0)x--;
			      if(y-1>=0)y--;
                  if(x==0 && y==0 && s[x]!=t[y])break;
			  }
		  }
	}
	return soln;	
}
public:
    string shortestCommonSupersequence(string a, string b) {
        int sz1=a.size(),sz2=b.size();
	if(a.size()==0)return b;
	if(b.size()==0)return a;
	string lcs=findLCS(sz1,sz2,a,b);
    cout<<lcs<<endl;
    int i=0,j=0,k=0;
	string soln="";
	while(k<lcs.size()){
			while(i<sz1 && a[i]!=lcs[k]){
				soln+=a[i++];
			}
			while(j<sz2 && b[j]!=lcs[k]){
				soln+=b[j++];
			}
			soln+=a[i];
			i++,j++,k++;
	}
	while(i<sz1){
		soln+=a[i++];
	}
	while(j<sz2){
		soln+=b[j++];
	}
	return soln;
    }
};