#include <iostream>
#include <vector>
#include <string>
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

void soln() {
    int n, m;
    cin >> n >> m;
    
    vector<string> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> change_indices(m);

    for (int i = 0; i < m; i++) {
        vector<int> lasts;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == '*') {
                lasts.pb(j);
            }
            if (a[j][i] == 'o') {
                for (auto it : lasts) {
                    change_indices[i].pb(it);
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (auto idx : change_indices[i]) {
            a[idx][i] = '*';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    ll t;
    cin >> t;
    while (t--) 
    soln();
    return 0;
}