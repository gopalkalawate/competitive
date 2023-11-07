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
void soln(){
    int n,k;cin>>n>>k;
    vector <ll> a(n);
    f(i,n) cin>>a[i];

    vector <ll> premax(n),postmax(n);
    ll maxi = a.front();

    for(int i=0;i<n;i++){
        maxi = max(maxi,a[i]);
        premax[i] = maxi;
    }
    maxi = a.back();
    for(int i=n-1;i>=0;i--){
        maxi = max(maxi,a[i]);
        postmax[i] = maxi;
    }
    sort(a.begin(),a.end());
    reverse(postmax.begin(),postmax.end());

    for(int i=1;i<=k;i++){
        if(!binary_search(a.begin(),a.end(),i)){
            cout<<0<<' ';
            continue;
        }
        int x = lower_bound(premax.begin(),premax.end(),i) - premax.begin();
        int y = lower_bound(postmax.begin(),postmax.end(),i) - postmax.begin();

        cout<<2*((n-y)-(x) )<<' ';
    }
    cout<<'\n';
}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}