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

    int n,k;cin>>n>>k;
    vector <pair<int,int>> noandParity(n,{0,0});

    for(int i=0;i<n;i++) cin>>noandParity[i].F;

    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;
        noandParity[x-1].S++;
        noandParity[y-1].S++;
    }
   
    int ans = INT_MAX;

    for(auto it : noandParity){
        if(it.S&1){
            ans = min(ans,it.F);
        }
    }
    
}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}