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
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    
    for (int i = 0; i < v.size(); ++i) {
        os << v[i]<<' ';
    }
    os << endl;
    return os;
}

bool chk(vector <ll> &a,ll mid,vector <ll> &b){
    int n = a.size();
    ll you = 0;
    ll alli = 0;
    
    for(int i=0;i<n;i++){
        you += a[i];
        alli += b[i];
    }

    for(int i=0;i<(n+mid)/4 && i<n;i++){
        you -= a[i];
    }

    for(int i=0;i<max(0*1ll,(n+mid)/4 - mid) && i<n;i++){
        alli -=b[i];
    }

    if(you + 1ll*100*(mid+min(0*1ll,(n-(mid+n)/4)*1ll)) >= alli){
        return 1;
    }
    return 0;

}

void soln(){
    ll n;cin>>n;
    vector <ll> a(n),b(n);
    cin>>a>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll you = 0,alliya = 0;
    ll lo = 0,hi = 10*n,mid;

    while(hi-lo>1){
        mid = (lo+hi)/2;
        if(chk(a,mid,b)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    if(chk(a,lo,b)){
        cout<<lo<<endl;
    }
    else{
        cout<<hi<<endl;
    }
}
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
ll t;cin>>t;
while(t--) soln();
return 0;
}