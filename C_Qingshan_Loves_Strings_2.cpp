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
bool chk(string s){
    int hi = s.size() - 1, lo = 0;

    while(hi>lo){
        if(s[hi]==s[lo]){
            return false;
        }
        hi--;
        lo++;
    }

    return true;

}
void soln(){
    int n;cin>>n;
    string s;cin>>s;

    if(n&1){
        cout<<-1<<endl;
        return;
    }

    int hi = n-1, lo = 0;
    vector <int> ans;
    while(hi> lo){
        if(s[hi]!=s[lo]){
            lo++;
            hi--;
        }
        else{
            if(s[lo]=='1'){
                string tmp = s.substr(0,lo) + "01" +s.substr(lo,n-lo);
                ans.pb(lo+1);
                n = n+2;
                lo-=2;
                s = tmp;
            }
            else{
                string tmp = s.substr(0,hi+1) + "01" + s.substr(hi+1,n-hi-1);
                ans.pb(hi+1);
                n += 2;
                hi += 2;
                s = tmp;
            }
            if(ans.size() > 300){
                cout<<-1<<endl;
                return;
            }
        }
    }

    if(!chk(s)){
        cout<<-1<<endl;
        return;
    }

    cout<<s<<endl;
    return;

    cout<<ans.size()<<endl;
    cout<<ans;

}
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
ll t;cin>>t;
while(t--) soln();
return 0;
}