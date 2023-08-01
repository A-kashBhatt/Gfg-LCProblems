//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
       unordered_set<string>st;
       for(auto it:wordList)st.emplace(it);
       queue<vector<string>>q;
       q.push({startWord});
       int sz=startWord.size();
       if(startWord==targetWord)return {{startWord}};
       vector<vector<string>>soln;
       int level=0;
       vector<string>usedOnLevel={startWord};
       while(!q.empty()){
           vector<string> v=q.front();
           string curr=v.back();
           if(curr==targetWord){
               if(soln.size()==0)soln.push_back(v);
               else if(soln[0].size()==v.size())soln.push_back(v);
               else break;
           }
           q.pop();
           if(v.size()>level){
               level++;
               for(auto it:usedOnLevel)st.erase(it);
               usedOnLevel.clear();
           }
           for(int i=0;i<sz;i++){
               char c=curr[i];
               for(char x='a';x<='z';x++){
                   curr[i]=x;
                   if(st.find(curr)!=st.end()){
                       v.push_back(curr);
                       usedOnLevel.push_back(curr);
                       q.push(v);
                       v.pop_back();
                   }
               }
               curr[i]=c;
           }
       }
       return soln;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends