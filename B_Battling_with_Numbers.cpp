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
void soln(){
    ll n;cin>>n;
    vector <ll> a(n),ap(n);
    cin>>a>>ap;
    ll m;
    cin>>m;

    vector <ll> b(n),bp(n);
    cin>>b>>bp;

    map <ll,ll> ma,mb;

    for(int i=0;i<n;i++){
        ma[a[i]] = ap[i];
    }

    for(int i=0;i<m;i++){
        mb[b[i]] = bp[i];
    }

    for(auto it : mb){
        if(ma.count(it.F)==0){
            cout<<0<<'\n';
            return;
        }
    }

    for(auto it : ma){
        if(mb.count(it.F)==0) continue;

        it.S -= mb[it.F];
    }

    ll ans = 1;

    for(auto it : ma){
        if(it.S==0) continue;

        else{
            ans++;
        }
    }

    ll ans1 = 1;

    while(ans){
        ans1 = (ans1*2)%M;
        ans--;
    }

    cout<<ans1<<'\n';

}
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
 soln();
return 0;
}