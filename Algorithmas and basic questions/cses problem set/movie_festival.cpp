#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 998244353
#define pb push_back

bool checker(vector <pair<ll, ll>>& v, int m) {
    for (int i = 0; i < m; i++) {
        // Perform some operations
    }
}

void soln() {
    int n;
    cin >> n;
    vector <pair<ll, ll>> a;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a.push_back({y, x});
    }

    sort(a.begin(), a.end());

    int count = 1,j=0;
    for (int i = 1; i < n; i++) {
        if(a[j].first <= a[i].second){
            j = i;
            count++;
        }
    }
    cout << count << '\n';
}

int main() {
    soln();
    return 0;
}
