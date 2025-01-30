//A good proble to practise on Sprague-Grundy Theorem
//Link to the problems: 1. https://codeforces.com/problemset/problem/2004/E
//                      2. https://atcoder.jp/contests/abc368/tasks/abc368_f

//Code for second problem

#include<bits/stdc++.h>
using namespace std;

#define yo printf("Anna\n")
#define na printf("Bruno\n");

#define vi             vector <int>
#define input(a,n)		for(int i=0;i<n;i++) cin>>a[i];

typedef long long ll;

const int N = 100005;

vi a(N+1);

int mex(set<int>&a){
    for(int i=0;;i++){
        if(!a.count(i)) return i;
    }
    return -1;
}

void nim(int n){
    
    for(int i=2;i<=n;i++){
        //cond
        set<int> poss;
        poss.insert(a[1]);
        for(int j=2;j*j<=i;j++){
            if(i%j) continue;
            poss.insert(a[j]);
            poss.insert(a[i/j]);
        }
        a[i]=mex(poss);
    }
}

void solve() {
    int n;
    cin >> n;

    vi p(n);
    input(p,n);

    int xr=0;
    for(int i=0;i<n;i++) xr^=a[p[i]];

    if(xr) yo;
    else na;
}

int32_t main()
{
    int t = 1;
    nim(N);
    while (t--) solve();
}
