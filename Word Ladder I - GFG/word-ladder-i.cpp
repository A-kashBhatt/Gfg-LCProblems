//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
       unordered_set<string>st;
       for(auto it:wordList)st.emplace(it);
       queue<pair<string,int>>q;
       q.push({startWord,1});
       int sz=startWord.size();
       if(st.find(startWord)!=st.end())st.erase(startWord);
       if(startWord==targetWord)return 1;
       while(!q.empty()){
           string curr=q.front().first;
           int seq=q.front().second;
           q.pop();
           for(int i=0;i<sz;i++){
               char c=curr[i];
               for(char x='a';x<='z';x++){
                   curr[i]=x;
                   if(st.find(curr)!=st.end()){
                       if(curr==targetWord)return seq+1;
                       q.push({curr,seq+1});
                       st.erase(curr);
                   }
               }
               curr[i]=c;
           }
       }
       return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends