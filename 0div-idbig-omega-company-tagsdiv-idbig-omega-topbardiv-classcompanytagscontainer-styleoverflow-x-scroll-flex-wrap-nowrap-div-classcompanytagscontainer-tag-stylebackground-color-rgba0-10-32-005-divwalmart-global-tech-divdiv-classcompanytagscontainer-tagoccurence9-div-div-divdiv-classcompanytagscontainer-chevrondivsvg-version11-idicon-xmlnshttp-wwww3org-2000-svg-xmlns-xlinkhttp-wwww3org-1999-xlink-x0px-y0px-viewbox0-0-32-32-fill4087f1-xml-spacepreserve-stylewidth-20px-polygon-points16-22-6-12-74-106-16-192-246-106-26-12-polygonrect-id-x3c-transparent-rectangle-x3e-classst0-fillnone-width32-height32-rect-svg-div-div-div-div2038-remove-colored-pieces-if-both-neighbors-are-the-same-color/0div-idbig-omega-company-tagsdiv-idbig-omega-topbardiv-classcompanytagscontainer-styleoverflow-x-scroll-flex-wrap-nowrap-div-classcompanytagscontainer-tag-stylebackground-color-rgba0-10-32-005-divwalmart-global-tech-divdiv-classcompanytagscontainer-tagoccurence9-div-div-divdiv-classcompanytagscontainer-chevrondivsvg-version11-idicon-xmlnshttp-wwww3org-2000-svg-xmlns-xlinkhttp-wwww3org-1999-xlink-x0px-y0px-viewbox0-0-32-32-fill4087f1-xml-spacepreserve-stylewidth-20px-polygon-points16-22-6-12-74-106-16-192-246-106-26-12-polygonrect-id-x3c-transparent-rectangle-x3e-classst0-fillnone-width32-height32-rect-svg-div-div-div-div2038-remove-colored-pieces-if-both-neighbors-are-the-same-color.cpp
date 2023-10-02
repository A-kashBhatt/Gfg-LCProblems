class Solution {
public:
    bool winnerOfGame(string colors) {
        int sz=colors.size();
        vector<int>alice,bob;
        for(int i=1;i<sz-1;i++){
            if(colors[i]=='A')alice.push_back(i);
            else bob.push_back(i);
        }
        int i=0,j=0;
        while(1){
            //Alice move
            bool flag1=false,flag2=false;
            while(i<alice.size()){
                if(colors[alice[i]-1]=='A' && colors[alice[i]+1]=='A'){
                    colors[alice[i]]=colors[alice[i]-1];
                    flag1=true;
                    i++;
                    break;
                }
                i++;
            }
            
            if(flag1==false)return false;
            
            //Bob move
            while(j<bob.size()){
                if(colors[bob[j]-1]=='B' && colors[bob[j]+1]=='B'){
                    colors[bob[j]]=colors[bob[j]-1];
                    flag2=true;
                    j++;
                    break;
                }
                j++;
            }
            if(flag2==false) return true; 
            
        }
        return true;
    }
};