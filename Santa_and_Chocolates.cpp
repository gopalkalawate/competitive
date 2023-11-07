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
    ll n,k;cin>>n>>k;
    vector <ll> a(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }

    if(sum < n){
        cout<<"NO\n";
        return;
    }

    if(sum%n!=0 && k==0){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

}
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
ll t;cin>>t;
while(t--) soln();
return 0;
}