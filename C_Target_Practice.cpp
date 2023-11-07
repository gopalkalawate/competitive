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
    vector <string> a(10);
    f(i,10){
        cin>>a[i];
    }
    int ans = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){

            if(a[i][j]!='X') continue;

            if(min(i,j)==0 || max(i,j)==9){
                ans += 1;
            }
            else if(min(i,j)==1 || max(i,j)==8){
                ans += 2;
            }
            else if(min(i,j)==2 || max(i,j)==7){
                ans += 3;
            }
            else if(min(i,j)==3 || max(i,j)==6){
                ans += 4;
            }
            else{
                ans += 5;
            }
        }
    }

    cout<<ans<<'\n';

}
int main(){
ll t;cin>>t;
while(t--) soln();
return 0;
}