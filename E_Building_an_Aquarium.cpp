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

bool checker(ll x,vector <ll> &a,ll mid){
    ll water = 0;

    int n = a.size();

    for(int i=0;i<n;i++){
        if(a[i]<=mid){
            water += mid - a[i];
        }
    }

    if(water<=x){
        return 1;
    }

    else{
        return 0;
    }

}

void soln(){
    ll n,x;cin>>n>>x;

    vector <ll> a(n);

    f(i,n) cin>>a[i];

    sort(a.begin(),a.end());

    ll hi = 1e10,lo =0,mid;
    
    while(hi-lo>1){
        mid = (hi+lo)/2;

        if(checker(x,a,mid)){
            lo = mid;
        }
        else{
            hi = mid -1;
        }
    }

    if(checker(x,a,hi)){
        cout<<hi<<'\n';
    }
    else{
        cout<<lo<<'\n';
    }

}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}