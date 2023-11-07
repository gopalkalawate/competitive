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

    vector <int> a(n);

    for(int i=0;i<n;i++){
        a[i] = i+1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            vector <int>forchek(n,0);
            int summ = 0;
            for(int k=0;k<n;k++){
                if(k!=i && k!=j){
                    summ = a[k] * a[k];
                }
                else{
                    summ = a[i]*a[j];
                }
                forchek[k] = summ;
            }
            int maxi = *max_element(forchek.begin(),forchek.end());
            summ = 0;
            for(int k=0;k<n;k++){
                summ += forchek[k];
            }

            for(int k=0;k<n;k++){
                if(forchek[k] == maxi){
                    summ = summ - forchek[k];
                    break;
                }
            }
            ans = max(summ,ans);
            //summ = 0;
        }
    }
    cout<<ans<<'\n';
}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}