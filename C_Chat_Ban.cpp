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
vector <int> binary(int n){
    vector <int> s(32);
    int last = 31;
    while(n){
        s[last] = n%2;
        n/=2;
        last--;
    }
    return s;
}

bool check(unsigned ll mid,unsigned ll k,unsigned ll x){ // if ban -> 1
    if(mid<=k){
        if(mid*(mid+1)/2*1ll<x){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        if(mid-k>k-1){
            return 0;
        }

        unsigned ll sum = k*(k+1)/2 ;
        unsigned ll sum1 = (k-1)*k/2  - (2*k-mid-1)*(2*k-mid)/2 ;

        if(sum1+sum >= x){
            return 1;
        }
        else{
            return 0;
        }

    }
}

void soln(){
    unsigned ll k,x;cin>>k>>x;

    unsigned ll lo = 1,hi = 2*k*1ll-1,mid ;

    while(hi-lo > 1){
        mid = (hi+lo)/2 ;
        if(check(mid,k,x)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }

    //cout<<lo<<" "<<hi<<" -> ";

    if(check(lo,k,x)){
        cout<<lo<<'\n';
    }
    else{
        cout<<hi<<'\n';
    }

}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}