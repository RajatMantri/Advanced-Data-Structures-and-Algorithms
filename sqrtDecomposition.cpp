int m=0,distinct=0,cnt[10*N];

struct node{
    int l,r,i;

    bool operator <(node&p){
        return make_pair(l/m,r)<make_pair(p.l/m,p.r);
    }
};

void add(int val){
    cnt[val]++;
    if(cnt[val]==1) distinct++;
}

void remove(int val){
    cnt[val]--;
    if(cnt[val]==0) distinct--;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];

    m=sqrt(n)+1;

    int query;
    cin>>query;

    node q[query];

    for(int i=0;i<query;i++){
        int l,r;cin>>l>>r;
        l--;r--;
        q[i].i=i,q[i].l=l,q[i].r=r;
    }

    sort(q,q+query);
    
    int x=0,y=0;

    vector<int> ans(query);
    
    for(int i=0;i<query;i++){
        while(x<q[i].l){
            remove(a[x]);
            x++;
        }

        while(x>q[i].l){
            x--;
            add(a[x]);
        }

        while(y<=q[i].r){
            add(a[y]);
            y++;
        }

        while(y>q[i].r+1){
            y--;
            remove(a[y]);
        }

        ans[q[i].i]=distinct;
    }

    for(int i=0;i<query;i++) cout<<ans[i]<<endi;
}