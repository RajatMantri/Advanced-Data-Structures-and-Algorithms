//Link to the problem: https://codeforces.com/problemset/problem/126/B

#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 7;

ll power(ll a, ll b,int mod){
    ll res=1;
    while(b>0){
        if(b&1){
            res=(a*res)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res%mod;
}

bool solve(int len,vector<pair<int,int>>& hash){
    int n=hash.size();
    pair<int,int> p=hash[len-1];
    ll f=power(31,len,mod1);
    ll g=power(37,len,mod2);
    for(int i=1;i<n-len;i++){
        int x=(hash[len+i-1].first-hash[i-1].first*f%mod1+mod1)%mod1;
        int y=(hash[len+i-1].second-hash[i-1].second*g%mod2+mod2)%mod2;
        if(p.first==x&&p.second==y) return 1;
    }
    return 0;
}

int main(){
    string s;
    cin>>s;

    int n=s.length();

    vector<pair<int,int>> prefixhash(n);
    vector<pair<int,int>> suffixhash(n);

    int p=31,q=37;
    ll x=0,y=0;
    for(int i=0;i<n;i++){
        x=(x*p+s[i]-'a'+1)%mod1;
        y=(y*q+s[i]-'a'+1)%mod2;
        prefixhash[i]={x,y};
    }

    x=0,y=0;
    ll a=1,b=1;
    for(int i=n-1;i>=0;i--){
        x=(x+(s[i]-'a'+1)*a)%mod1;
        y=(y+(s[i]-'a'+1)*b)%mod2;

        a=(a*p)%mod1;
        b=(b*q)%mod2;
        suffixhash[n-i-1]={x,y};
    }

    vector<int> len;
    for(int i=0;i<n-1;i++){
        if(prefixhash[i]==suffixhash[i]) len.push_back(i+1);
    }

    int l=0,r=len.size()-1,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        int f=len[mid];

        if(solve(f,prefixhash)){
            ans=f;
            l=mid+1;
        }
        else r=mid-1;
    }

    if(ans!=-1) cout<<s.substr(0,ans);
    else cout<<"Just a legend";

}