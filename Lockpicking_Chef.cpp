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

bool checker(string a, string b, int mid){
    int n = a.size();
    int m = b.size();

    int ans = INT_MAX;
    int check = 0;
    for(int i = 0; i <= n - m; i++){  
        check = 0;
        for(int j = 0; j < m; j++){
            int inr = 0, dcr = 0;
            if(a[i+j] > b[j]){
                inr = (10 + b[j] - a[i+j]) % 10;  
                dcr = (a[i+j] - b[j]) % 10;  
            }
            else{
                inr = (10 + a[i+j] - b[j]) % 10;  
                dcr = (b[j] - a[i+j]) % 10;  
            }
            check += min(inr, dcr);
        }
        ans = min(check, ans);
    }

    if(ans <= mid){
        return true;
    } else {
        return false;
    }
}


void soln(){
    int n,m;cin>>n>>m;
    string a,b;cin>>a>>b;

    int hi = 1e5,lo = 0,mid;

    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(checker(a,b,mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }

    if(checker(a,b,lo)){
        cout<<lo<<'\n';
    }
    else{
        cout<<hi<<'\n';
    }

}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}