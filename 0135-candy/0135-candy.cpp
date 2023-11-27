class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz=ratings.size();
        vector<int>v(sz,1);
        for(int i=1;i<sz;i++){
            if(ratings[i]>ratings[i-1])v[i]=v[i-1]+1;
        }
        for(int i=sz-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])v[i]=max(v[i],v[i+1]+1);
        }
        int ans=accumulate(v.begin(),v.end(),0);
        return ans;
        
    }
};