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

void soln(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)); 

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j] - '0';
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==0){
                cout<<"NO\n";
                return;
            }
            if(a[i][j]==0 && a[i+1][j] && a[i][j+1] && a[i+1][j+1]){
                cout<<"NO\n";
                return;
            }
            if(a[i][j] && a[i+1][j] && a[i][j+1]==0 && a[i+1][j+1]){
                cout<<"NO\n";
                return;
            }
            if(a[i][j] && a[i+1][j]==0 && a[i][j+1] && a[i+1][j+1]){
                cout<<"NO\n";
                return;
            }

        }
    }

    cout<<"YES\n";

    
}

int main(){
    ll t;
    cin >> t;
    while(t--) soln();
    return 0;
}
