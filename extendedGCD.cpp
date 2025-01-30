vector<int> extendedGCD(int a,int b){
    if(b==0){
        return {1,0,a};
    }

    vector<int> res=extendedGCD(b,a%b);
    int gcd=res[2];
    int x=res[1];
    int y=res[0]-a/b*res[1];

    return {x,y,gcd};
}