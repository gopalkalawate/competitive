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

template <typename T>
std::istream &operator>>(std::istream &in, std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        in >> v[i];
    }
    return in;
}

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

vector<bool> binary(int n) {
    vector<bool> s(32);
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
    vector<int> a(n);
    cin >> a;
    vector<vector<bool>> bin;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        vector<bool> bb = binary(a[i]);
        bin.pb(bb);
    }

    vector<vector<bool>> ans(n, vector<bool>(32));

    vector<bool> prev = binary(a[0]);
    
    for(int i=1;i<n;i++){
        for(int j=0;j<32;j++){
            if(prev[j]==0){
                prev[j] = ans[i][j]^bin[i][j];
                ans[i][j] = 0;
                
            }
            else{
                ans[i][j] = bin[i][j]^1;
                prev[j] = (bin[i][j]^ans[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int anss = 0;
        for (int j = 0; j < 32; j++) {
            anss += ans[i][j] << (31 - j);
        }
        cout << anss << ' ';
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) soln();
    return 0;
}
