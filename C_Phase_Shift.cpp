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

void soln(){
    int n;cin>>n;
    string s;cin>>s;
    set <int> st;map<int,int> m;

    for(int i=0;i<26;i++) st.insert(i);

    dsu gr(26);

    for(auto it : s){
        int t = it - 'a';

        if(m.find(t)!=m.end()) continue; 

        if(m.size()==25){
            m[t] = *st.begin();
            continue;
        }

        for(auto i : st){
            if(gr.find_set(i)!=gr.find_set(t)){
                m[t] = i;
                gr.union_set(t,i);
                break;
            }
        }
        st.erase(st.find(m[t]));
    }

    for(auto it : s){
        cout<<char(m[it-'a'] + 'a');
    }cout<<endl;
    

}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}