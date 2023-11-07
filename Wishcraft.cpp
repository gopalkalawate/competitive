#include <bits/stdc++.h>
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
std::istream &operator>>(std::istream &in, std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        in >> v[i];
    }
    return in;
}
//<--------------Some functions and data structures------->
// dsu data structure
struct dsu {
    vector<int> parent, size;
    dsu(int n) {
        parent.assign(n + 1, 0);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find_set(int v) {  // finds parent of the root
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u != v) {
            if (size[u] > size[v]) {
                swap(u, v);
            }
            parent[u] = v;
            size[v] += size[u];
        }
    }
};
vector<int> binary(int n) {
    vector<int> s(32);
    int last = 31;
    while (n) {
        s[last] = n % 2;
        n /= 2;
        last--;
    }
    return s;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << ' ';
    }
    os << endl;
    return os;
}
void soln() {
    int n;
    cin >> n;
    int p, q;
    cin >> p >> q;
    multiset<ll> b,s;
    
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        b.insert(t);
    }
    
    s = b;
    
    while ( *s.begin() < 0 && q > 0 && s.size() > 1) {
        auto it = s.end();
        it--;
        ll l = *it;
        s.erase(it);
        it = s.begin();
        ll k = *it;
        s.erase(it);
        s.insert(l - k);
        q--;
    }
    
    while (p>0  && s.size() > 1) {
    if (!s.empty()) {
        auto it = s.end();
        it--;
        ll k = *it;
        s.erase(it);

        it = s.end();
        it--;
        ll l = *it;
        s.erase(it);
        s.insert(k + l);
        p--;
    }
}

while (q>0 && s.size() > 1) {
    if (!s.empty()) {
        auto it = s.end();
        it--;
        ll k = *it;
        s.erase(it);
        it = s.begin();
        ll l = *it;
        s.erase(it);
        s.insert(k - l);
        q--;
    }
}

    
    // for(auto it : s){
    //     cout<<it<<' ';
    // }
    // cout<<endl;
    // return;

    ll ans = -1e18;
    
    for (auto it : s) {
        ans = max(it, ans);
    }

    ll mini = 1e18;

    for(auto it : s){
        mini = min(mini,it);
    }

    cout<<ans-mini<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) soln();
    return 0;
}
