class Solution {
public:
    int compareVersion(string version1, string version2) {
        int sz1=version1.size(),sz2=version2.size();
        int i=0,j=0;
        while(i<sz1 || j<sz2){
            string a="",b="";
            while(i<sz1 && version1[i]=='0')i++;
            while(j<sz2 && version2[j]=='0')j++;
            while(i<sz1 && version1[i]!='.')a+=version1[i++];
            while(j<sz2 && version2[j]!='.')b+=version2[j++];
            int x=0,y=0;
            if(a!="")x=stoi(a);
            if(b!="")y=stoi(b);
            if(x>y)return 1;
            else if(x<y)return -1;
            i++,j++;
        }
        return 0;
    }
};