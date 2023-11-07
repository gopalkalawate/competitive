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

int findFirstSetBitPosition(int n) {
    int position = 1;
    int mask = 1;

    while ((n & mask) == 0) {
        mask <<= 1;
        position++;
    }

    return position-1;
}

void soln(){
    ll n,q;cin>>n>>q;
    vector <ll> a(n),b(q),lastset(n);

    cin>>a;
    cin>>b;

    vector <ll> adds;  // in worst case the size if adds will be 30
    ll maxi = 40;
    for(int i=0;i<q;i++){
        if(b[i]<maxi){
            maxi = b[i];
            adds.pb(b[i]);
        }
    }

    for(int i=0;i<n;i++){
        lastset[i] = findFirstSetBitPosition(a[i]);
    }


    int k = adds.size();

    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            if(lastset[j]>=adds[i]){
                a[j] += pow(2,adds[i]-1);
                lastset[j] = min(lastset[j],adds[i] - 1);
            }
        }
    } // 30 * n

    cout<<a;

    

}
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);

// cout<<findFirstSetBitPosition(3);
// return 0;

ll t;cin>>t;
while(t--) soln();
return 0;
}