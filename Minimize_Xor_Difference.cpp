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

vector <ll> binary(ll n){
    vector <ll> a(32,0);
    int last = 31;
    while(n){
        a[last] = n%2;
        n/=2;
        last--;
    }
    return a;
}

void soln(){
    ll a,b;cin>>a>>b;
    if(a<b) swap(a,b);
    vector <ll> aa = binary(a);
    vector <ll> bb = binary(b);
    vector <ll> ans(32);

    int first = 1;

    for(int i=0;i<32;i++){
        if(aa[i]==1 && first){
            
            if(bb[i]==1){
                
                continue;
            }
            first = 0;
            continue;
        }
        if(aa[i]==1 && bb[i]==0){
            ans[i] = 1;
        }
        
        else{
            ans[i] = 0;
        }
    }

    ll anss = 0;

    for(int i=0;i<32;i++){
        if(ans[i]==1){
            anss += (1<<(31-i))*1ll;
        }
    }
    cout<<anss<<'\n';
}
int main(){

ll t;cin>>t;
while(t--) soln();
return 0;
}