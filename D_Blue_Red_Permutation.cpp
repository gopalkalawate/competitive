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
#define f(i, n) for (int i = 0; i < n; i++)

template <typename T>
std::istream &operator>>(std::istream &in, std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        in >> v[i];
    }
    return in;
}

// Some functions and data structures

// dsu data structure
struct dsu {
    vector<int> parent, size;
    dsu(int n) {
        for (int i = 0; i <= n; i++) {
            parent.pb(i);
        }
        size.assign(n + 1, 1);
    }
    int find_set(int v) {
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
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << ' ';
    }
    os << endl;
    return os;
}

void soln() {
    int n;
    cin >> n;
    vector<pair<int, bool>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
    }

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'B') {
            a[i].S = 0;
        } else {
            a[i].S = 1;
        }
    }

    sort(a.begin(), a.end());

    // Add your logic to use the 'a' vector and 'm' map here
    map<int, pair<int, int>> m;

    for (int i = 0; i < n; i++) {
        if (a[i].S == 0) {
            m[a[i].F].S++;
        } else {
            m[a[i].F].F++;
        }
    }
    int adds = 0;
    int ends = 0;
    for(auto it : m){
        if(it.F<1){
            adds += it.S.S;
        }
        if(it.F>n){
            ends += it.S.F;
        }
    }
    if(adds!=0 || ends!= 0){
        cout<<"NO\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(m.count(i)){
            adds += m[i].S;
        }
        if(adds>i){
            cout<<"NO\n";
            return;
        }
    }

    int j = 1;
    for(int i=n;i>=1;i--){
        if(m.count(i)){
            ends += m[i].F;
        }
        if(ends>j){
            cout<<"NO\n";
            return;
        }
        j++;
    }

    cout<<"YES\n";
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) soln();
    return 0;
}
