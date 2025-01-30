const int sz=3;

struct mat{
    ll m[sz][sz];

    mat(){
        memset(m,0,sizeof(m));
    }

    void identity(){
        for(int i=0;i<sz;i++) m[i][i]=1;
    }

    mat operator *(mat b){
        mat ans;
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                for(int k=0;k<sz;k++){
                    ans.m[i][j]=(ans.m[i][j]+m[i][k]*b.m[k][j])%mod;
                }
            }
        }

        return ans;
    }

    mat power(int n,mat a){
        mat t;
        t.identity();
        while(n>0){
            if(n&1){
                t=(t*a);
            }
            a=(a*a);
            n>>=1;
        }
        return t;
    }
};

ll solve(int n) {
    if(n==1||n==0) return n;
    if(n==-1) return 0;
    mat d;
    d.m[0][0]=d.m[0][1]=d.m[0][2]=1;
    d.m[1][1]=d.m[1][2]=1;
    d.m[2][1]=1;

    d=d.power(n-1,d);

    return (d.m[0][0]+d.m[0][1])%mod;
}