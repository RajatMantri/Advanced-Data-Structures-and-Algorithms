typedef long long ll;
const ll mod = 1e9 + 7;

ll power(ll a, ll b){
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

//a*b=a+a+a+...  b times
ll binary_mul(ll a,ll b){
    ll res=0;
    while(b>0){
        if(b&1){
            res=(res+a)%mod;
        }
        a=(a+a)%mod;
        b>>=1;
    }
    return res%mod;
} 






