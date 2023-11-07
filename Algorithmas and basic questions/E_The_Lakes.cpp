#include<iostream>
using namespace std;
#define ll long long
#define M 998244353
#define pb push_back

// Typical Question on dfs for graph using matrix method

int n,m;
bool vis[1005][1005];
int a[1005][1005];

int dfs(int i,int j){
    vis[i][j] = true;
    int ans = a[i][j];

    if(i!=0 && vis[i-1][j]==0 && a[i-1][j]!=0) ans += dfs(i-1,j);

    if(i+1<n && vis[i+1][j]==0 && a[i+1][j]!=0) ans += dfs(i+1,j);

    if(j!=0 && vis[i][j-1]==0 && a[i][j-1]!=0) ans += dfs(i,j-1);

    if(j+1<m && vis[i][j+1]==0 && a[i][j+1]!=0) ans += dfs(i,j+1);


    return ans;
}

void soln(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=false;
            cin>>a[i][j];
        }
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==0 && a[i][j]!= 0){
                ans = max(ans,dfs(i,j));
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){
    int t;cin>>t;
    while(t--){
        soln();
    }
}