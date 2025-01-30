const int N=1e5+1;
vector<bool> isprime(N,1);
vector<int> highestPrime(N,1);
vector<int> lowestPrime(N,1);

void sieve(){
    isprime[1]=isprime[0]=0;
    for(int i=2;i<N;i++){
        if(isprime[i]){
            lowestPrime[i]=highestPrime[i]=i;
            for(int j=i*2;j<N;j+=i){
                isprime[j]=0;
                highestPrime[j]=i;
                if(lowestPrime[j]==0) lowestPrime[j]=i;
            }
        }
    }
}

map<int,int> primeFactors(int n){
    map<int,int> freq;
    while(n>1){
        int prime=highestPrime[n];
        while(n%prime==0){
            freq[prime]++;
            n/=prime;
        }
    }
    return freq;
}

vector<bool> segemented_sieve(ll L, ll R){
    vector<bool> isPrime(R-L+1,true);
    for (ll i=2;i*i<=R;i++){
        if(isprime[i]==0) continue;
        ll a=(L/i)*i;
        if(a<L) a+=i;
        if(i>=L&&i<=R){
            a=2*i;
        }
        for (ll j=a;j<=R;j+=i){
            isPrime[j-L]=0;
        }
    }
    if (L==1) isPrime[0]=0;
    return isPrime;
}