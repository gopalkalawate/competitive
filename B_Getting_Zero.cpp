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

vector <int> binary(int n){
    vector <int> s(16);
    
    for(int i=15;i>=0;i--){
        s[i] = n%2;
        n/=2;
    }

    return s;
}

void soln(){
    int n;cin>>n;
    vector <int> a(n);
    f(i,n) cin>>a[i];
    // int check = 16;
    for(int i=0;i<n;i++){
        int ans = INT_MAX;
        int prev = a[i];
        for(int j=0;j<16;j++){
            int count = 0;
            a[i] += j;
            count += j;


            vector <int> binary_ = binary(a[i]);

            for(int k=15;k>=0;k--){
                if(binary_[k]==1){
                    count += k;
                    break;
                }
            }

            ans = min(ans,count);
            a[i] = prev;
        }
       
        cout<<ans<<" ";
    }
    
    cout<<endl;
}
int main(){
    
 soln();
return 0;
}