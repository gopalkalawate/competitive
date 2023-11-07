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
void soln(){
    int n;cin>>n;
    int H,Mi;cin>>H>>Mi;

    vector <pair<int,int>> a(n);

    f(i,n){
        cin>>a[i].F>>a[i].S;
    }

    sort(a.begin(),a.end());

    bool check = 1;

    for(int i=0;i<n;i++){
        if(a[i].F > H){
            check = 0;
            if(a[i].S < Mi){
                a[i].F--;
                a[i].S += 60;
            }
            cout<<a[i].F - H<<" "<<a[i].S - Mi<<'\n';
            return;
        }
        else if(a[i].F==H){
            // check = 0;
            int ans = a[i].S - Mi;
            if(ans>=0){
                cout<<0<<" "<<ans<<'\n';
                return;
            }
        }
    }

    if(check){
        int hr = 23-H;
        int mii = 60 - Mi;

        if(mii>=60){
            mii -= 60;
            hr++;
        }

        hr += a[0].F;
        mii += a[0].S;

        if(mii>=60){
            mii -= 60;
            hr++;
        }
        cout<<hr<<" "<<mii<<'\n';
    }

}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}