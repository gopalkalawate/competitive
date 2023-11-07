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
    string a,s;cin>>a>>s;


    

    int i = a.size() - 1;int j = s.size()-1;
    vector <int> ans;
    while(i>=0 && j>=0){
        
        if(a[i]-'0' > s[j] - '0'){
            j--;
            int k = (s[j] - '0')*10 + (s[j+1] - '0') - (a[i] - '0');
            if(k<0){
                cout<<-1<<'\n';
                return;
            }
            if(k>=10){
                cout<<-1<<'\n';
                return;
            }
            ans.pb(k);
        }
        else{   
            int k = (s[j] - '0') - (a[i] - '0');
            if(k>=10){
                cout<<-1<<'\n';
                return;
            }
            if(k<0){
                cout<<-1<<'\n';
                return;
            }
            ans.pb(k);
        }
        
        if(i>j){
            cout<<-1<<'\n';
            return;
        }

        i--;j--;
    }

    while(j>=0){
        ans.pb(s[j]-'0');
        j--;
    }
    while(i>=0){
        ans.pb(s[i]-'0');
        i--;
    }

    reverse(ans.begin(),ans.end());

    int k = ans.size();
    int start = 0;
    for(int i=0;i<k;i++){
        if(ans[i]!=0){
            start = i;
            break;
        }
    }

    for(int i=start;i<k;i++){
        cout<<ans[i];
    }
    cout<<endl;
}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}