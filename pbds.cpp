//A problem using policy based data structure
//Link to the problem: https://codeforces.com/contest/459/problem/D

#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define vi             vector <int>
#define input(a,n)		for(int i=0;i<n;i++) cin>>a[i];

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    input(a,n);

    ordered_set s;
    map<int,int> mp;
    map<int,int> freq;
    
    int suff[n];
    for(int i=n-1;i>=0;i--){
        freq[a[i]]++;
        suff[i]=freq[a[i]];
        s.insert({suff[i],mp[suff[i]]});
        mp[suff[i]]++;
    }

    freq.clear();
    ll ans=0;

    for(int i=0;i<n;i++){
        s.erase({suff[i],mp[suff[i]]-1});
        mp[suff[i]]--;
        freq[a[i]]++; 
        ans+=s.order_of_key({freq[a[i]],0});
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}