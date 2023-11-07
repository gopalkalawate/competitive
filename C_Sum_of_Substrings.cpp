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
    int n,k;cin>>n>>k;
    string s;cin>>s;

    int backswaps = 0,idx = n-1;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            if(backswaps>k) break;
            backswaps++;
            idx--;
        }
        else{
            break;
        }
    }
    int last1 =n;
    if(backswaps<=k){
        swap(s.back(),s[idx]);
        k -= backswaps;
        //ok++;
    }

    for(int i=n-1;i>=0;i--){
        if(backswaps<=k && s[i]=='1'){
            last1 = i;
            break;
        }
    }

    // cout<<last1<<endl;
    // return;

    // cout<<s<<endl;
    // return;
    int front=0;
    for(int i=0;i<last1;i++){
        if(s[i]=='0'){
            front++;
        }
        else{
            break;
        }
    }

    

    if(front<=k && front != last1){
        swap(s.front(),s[front]);
    }

    // cout<<s<<endl;
    // return;

    ll ans = 0;

    for(int i=0;i<n;i++){
        if(i==0){
            ans += (s[i]-'0')*10;
        }
        else if(i==n-1){
            ans += s[i] - '0';
        }
        else{
            ans += 11*(s[i]-'0');
        }
    }

    if(ans <0){
        cout<<0<<endl;
        return;
    }

    cout<<ans<<endl;

}
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
ll t;cin>>t;
while(t--) soln();
return 0;
}