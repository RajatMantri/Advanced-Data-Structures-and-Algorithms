vector <int> kmp(string &pat, string &txt){   
    vector<int> ans;
    int n=txt.length(),m=pat.length(),length=0,i=1;
    vector<int> lps(m);
    while(i<m){
        if(pat[i]==pat[length]){
            length++;lps[i]=length;i++;
        }
        else{
            if(length!=0) length=lps[length-1];
            else{
                lps[i]=0;i++;
            }
        }
    }
    int j=0;i=0;
    while(i<n){
        if(pat[j]==txt[i]){
            i++;j++;
            if(j==m) ans.push_back(i-j+1);
        }
        else{
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    return ans;
}