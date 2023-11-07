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

void soln() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i];

    ordered_set gk;

    for (int i = 0; i < k; i++) {
        gk.insert({{a[i], i}, i});
    }

    for (int i = k; i < n; i++) {
        auto x = *gk.find_by_order(k / 2);
        cout << x.first.first << " ";

        auto y = gk.find_by_order(i - k+1);
        gk.erase(y);

        gk.insert({{a[i], i}, i});
    }
    cout << endl;
}

int main() {
    
     soln();
    return 0;
}
