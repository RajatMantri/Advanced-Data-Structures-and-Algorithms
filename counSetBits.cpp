int countbits(int n){
    int count=0;
    while(n){
        count++;
        n=n>>1;
    }
    return count;
}
void countSetBits(int n,vector<int> &bit){
    if(n==0) return;

    int bits=countbits(n);
    bits--;
    int pow=1<<bits;

    for(int i=0;i<bits;i++){
        bit[i]+=pow/2;
    }

    bit[bits]+=n-pow+1;
    countSetBits(n-pow,bit);
}