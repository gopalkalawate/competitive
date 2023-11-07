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
    int n;cin>>n;
    vector <ll> a(n);
    f(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    a[0] += 1;

    ll product = 1;

    f(i,n){
        product *= a[i]*1ll;
    }
    cout<<product<<'\n';
}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}