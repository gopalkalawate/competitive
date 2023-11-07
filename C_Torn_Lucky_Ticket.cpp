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
    int n;cin>>n;
    vector <string> one,two,three,four,five;

    for(int i=0;i<n;i++){
        string s;cin>>s;
        if(s.size()==1) one.pb(s);
        if(s.size()==2) two.pb(s);
        if(s.size()==3) three.pb(s);
        if(s.size()==4) four.pb(s);
        if(s.size()==5) five.pb(s);
    }

    // 2 4

    map <ll,ll> m;
    ll ans = 0;
    for(auto it : two){
        m[((it[0]-'0')+(it[1]-'0'))*1ll]++;
    }

    for(auto it : four){
        ans += m[((it[1]-'0')+ (it[2]-'0') + (it[3]-'0') - (it[0]-'0'))*1ll]*1ll;
    }

    for(auto it : four){
        ans += m[((it[0]-'0') + (it[1]-'0') + (it[2]-'0') - (it[3]-'0'))*1ll]*1ll;
    }

    for(auto it : m){
        ans += it.S*it.S;
    }

    m.clear();
    // 1 all 
    for(auto it : one){
        m[(it[0]-'0')*1ll]++;
    }

    for(auto it : three){
        ans += m[((it[1]-'0') + (it[2]-'0') - (it[0]-'0'))*1ll]*1ll;
    }
    
    for(auto it : three){
        ans += m[((it[0]-'0') + (it[1]-'0') - (it[2]-'0'))*1ll]*1ll;
    }

    for(auto it : five){
        ans += m[(it[2]-'0') + (it[3]-'0') + (it[4]-'0') - (it[0]-'0') - (it[1]-'0')];
    }

    for(auto it : five){
        ans += m[(it[0]-'0') + (it[1]-'0') + (it[2]-'0') - (it[3]-'0') - (it[4]-'0')];
    }

    for(auto it : m){
        ans += it.S * it.S;
    }

    m.clear();
    //cout<<ans<<endl;

    for(auto it : three){
        m[(it[0]-'0') + (it[1]-'0') + (it[2]-'0')]++;
    }

    // 3 and rem
    for(auto it : five){
        ans += m[-(it[0]-'0')+(it[1]-'0') + (it[2]-'0') + (it[3]-'0') + (it[4]-'0')];
    }

    for(auto it : five){
        ans += m[(it[0]-'0')+(it[1]-'0') + (it[2]-'0') + (it[3]-'0') - (it[4]-'0')];
    }

    for(auto it : m){
        ans += it.S*it.S;
    }

    m.clear();

    //cout<<ans<<endl;
    // 5 5
    for(auto it : five){
        m[(it[0]-'0')+(it[1]-'0') + (it[2]-'0') + (it[3]-'0') + (it[4]-'0')]++;
    }

    for(auto it : m){
        ans += it.S*it.S;
    }

    m.clear();

    // 4 4

    for(auto it : four){
        m[(it[0]-'0')+(it[1]-'0') + (it[2]-'0') + (it[3]-'0')]++;
    }

    for(auto it : m){
        ans += it.S*it.S;
    }

    cout<<ans<<endl;
    
}
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
 soln();
return 0;
}