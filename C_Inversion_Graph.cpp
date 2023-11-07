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
    vector <int> a(n);
    f(i,n) cin>>a[i];

    vector <int> maxi(n),mini(n);

    int maxii = 0;

    for(int i=0;i<n;i++){
        maxii = max(maxii,a[i]);
        maxi[i] = maxii;
    }

    int minii = INT_MAX;

    for(int i=n-1;i>=0;i--){
        minii = min(minii,a[i]);
        mini[i] = minii;
    }

    int ans = 1;

    for(int i=0;i<n-1;i++){
        ans += bool(maxi[i]<mini[i+1]);
    }
    cout<<ans<<'\n';
}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}