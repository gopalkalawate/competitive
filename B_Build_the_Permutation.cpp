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
    int n,a,b;cin>>n>>a>>b;

    if(a+b>n-2){
        cout<<-1<<endl;
        return;
    }

    if(abs(a-b)>1){
        cout<<-1<<endl;
        return;
    }

    vector <int> aa(n);

    for(int i=0;i<n;i++){
        aa[i] = i+1;
    }


    if(a>b){
        int l = 0,hi = n-1;
        int x = a+b;
        int count = 0;
        while(x--){
            if(count&1){
                cout<<aa[hi--]<<' ';
            }
            else{
                cout<<aa[l++]<<' ';
                
            }
            count++;
        }

        for(int i = hi;i>=l;i--){
            cout<<aa[i]<<' ';
        }
    }

    else if(b>a){
        int l = 0,hi = n-1;
        int x = b+a;
        int count = 0;
        while(x--){
            if(count&1){
                cout<<aa[l++]<<' ';
               
            }
            else{
                cout<<aa[hi--]<<' ';
            }
            count++;
        }

        for(int i=l;i<=hi;i++){
            cout<<aa[i]<<' ';
        }

    }

    else{
        int x = a;
        for(int i=1;i<n-1;i++){
            if(x==0) break;
            if(i&1){
                swap(aa[i],aa[i+1]);
                x--;
            }
        }
        cout<<aa;
        return;
    }

    cout<<endl;

}
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
ll t;cin>>t;
while(t--) soln();
return 0;
}