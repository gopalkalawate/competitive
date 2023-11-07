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

ll req(int ind,vector <ll> &a,ll sum,ll attk,ll def){
    ll coins = 0;

    if(a[ind]<def){
        coins += def - a[ind];
    }

    if(sum-a[ind] < attk){
        coins += attk - sum + a[ind];
    }

    return coins;
}

ll ans(ll def,ll attk,vector <ll> &a,ll sum){
    int n = a.size();

    int x = lower_bound(a.begin(),a.end(),def) - a.begin();
    ll coins = 1e18;

    if(x==0){
        ll tmp = req(x,a,sum,attk,def);
        coins = min(coins , tmp);
    }

    else{
        
        ll tmp1 = req(x,a,sum,attk,def);
        ll tmp2 = req(x-1,a,sum,attk,def);

        coins = min(tmp1,tmp2);
    }
    return coins;
}

void soln(){

    int n;cin>>n;
    vector <ll> a(n);
    cin>>a;
    sort(a.begin(),a.end());
    ll k;cin>>k;

    ll sum = 0;

    f(i,n){
        sum += a[i];
    }

    while(k--){
        ll def,attk;cin>>def>>attk;

        cout<<ans(def,attk,a,sum)<<'\n';

    }

}
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
 soln();
return 0;
}