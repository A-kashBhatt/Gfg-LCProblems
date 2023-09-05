class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(auto it:arr){
            if(it<0) m[(k+(it%k))%k]++;
            else m[it%k]++;
        }
        for(auto it:m){
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(int i=1;i<k;i++){
            if(m[i]==0)continue;
            else if(2*i==k){
                if(m[i]%2)return false;
            }
            else{
                int x=m[i];
                int y=m[k-i];
                if(x!=y)return false;
                m[k-i]=0;
            }
        }
        if(m[0]%2)return false;
        return true;
    }
};