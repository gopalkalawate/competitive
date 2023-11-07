#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<pair<pair<int, int>, int>, null_type, less<pair<pair<int, int>, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define M 998244353
#define pb push_back
#define F first
#define S second
#define f(i,n) for(int i=0;i<n;i++)

bool checker(ll mid,vector <ll> &presum,vector <ll>&lsum,ll k){
    int n = presum.size();
    for(int i=0;i<=n-mid+1;i++){
        if(lsum[i]<mid) continue;
        if(presum[i+mid]-presum[i]<k){
            return true;
        }
    }
    return false;
}

void soln(){
    ll n,k;cin>>n>>k;
    vector <ll> a(n),h(n),presum(n+1),lsum(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>h[i];
    }

    presum[0] = 0;

    lsum[0] = 1;

    for(int i=1;i<n+1;i++){
        presum[i] += presum[i-1] + a[i-1];
    }

    lsum[n-1] = 1;

    for(int i=n-2;i>=0;i--){
        if(h[i]%h[i+1] == 0){
            lsum[i] = lsum[i+1]+1;
        }
        else{
            lsum[i] = 1;
        }
    }

    ll hi = 1e10,lo = 0,mid;

    while(hi-lo>1){
        mid = (hi+lo)/2;

        if(checker(mid,presum,lsum,k)){
            lo = mid;
        }

        else{
            hi = mid - 1;
        }
    }

    checker(hi,presum,lsum,k)==1 ? cout<<hi<<'\n' : cout<<lo<<'\n';
}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}