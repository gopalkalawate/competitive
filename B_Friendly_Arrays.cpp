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
    int n,m;cin>>n>>m;
    vector <int> a(n),b(m);
    f(i,n) cin>>a[i];
    f(i,m) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(n&1){
        int mini = a[0];
        for(int i=1;i<n;i++){
            mini = mini ^ a[i];
        }
        cout<<mini<<" ";

        int maxi;

        int all = b[0];

        for(int i=1;i<m;i++){
            all = all | b[i];
        }

        for(int i=0;i<n;i++){
            a[i] = a[i]|all;
        }

        int ans = a[0];

        for(int i=1;i<n;i++){
            ans ^= a[i];
        }
        cout<<ans<<'\n';
    }

    else{

        int maxi = a[0];

        for(int i=1;i<n;i++){
            maxi ^= a[i]; 
        }

        int all = b[0];

        for(int i=1;i<m;i++){
            all = all | b[i];
        }

        for(int i=0;i<n;i++){
            a[i] |= all;
        }

        int mini = a[0];

        for(int i=1;i<n;i++){
            mini ^= a[i];
        }

        cout<<mini<<" "<<maxi<<'\n';
    }

}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}