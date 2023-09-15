class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>soln;
        string s=words[0];
        unordered_map<string,int>m;
        for(auto it:s){
            string s(1,it);
            m[s]++;
        }
        for(int i=1;i<words.size();i++){
            unordered_map<string,int>m1;
            for(auto it:words[i]){
                string s(1,it);
                m1[s]++;
            }
            for(auto it:m){
                m[it.first]=min(m[it.first],m1[it.first]);
            }
        }
        for(auto it:m){
            int freq=it.second;
            while(freq!=0){
                soln.push_back(it.first);
                freq--;
            }
        }
        return soln;
    }
};