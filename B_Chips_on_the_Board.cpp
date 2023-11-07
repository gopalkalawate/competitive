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
// Overloading cin and cout operators for vectors

template <typename T>
std::istream &operator>>(std::istream &in, std::vector<T> &v)
{
for(int i =0;i<v.size();i++)
{
in>>v[i];
}
return in;
}
//<--------------Some functions and data structures------->
            // dsu data structure
struct dsu{
        vector <int> parent,size;
        dsu(int n){
        for(int i=0;i<=n;i++){
                parent.pb(i);
            }
        size.assign(n+1,1);
        }
        int find_set(int v){  // finds parent of the root 
            if(parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
        }
        void union_set(int u,int v){
            u = find_set(u);
        v = find_set(v);
            if(u!=v){
                if(size[u]>size[v]){
                swap(u,v);
                }
                parent[u]=v;
                size[v] += size[u];
        }
        }
    };
void soln(){
    ll n;cin>>n;
    vector <ll> a(n),b(n);
    cin>>a;
    cin>>b;

    ll mina = 1e18,minb = 1e18,suma = 0,sumb = 0;

    for(auto it : a){
        mina = min(mina,it);
        suma += it;
    }

    for(auto it : b){
        minb = min(minb,it);
        sumb += it;
    }

    ll ans = min(mina*n*1ll + sumb,minb*n*1ll + suma);

    cout<<ans<<'\n';
}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}