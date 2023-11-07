#include <bits/stdc++.h>

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define nl cout << "\n"
#define zero cout << '0' << endl
#define mone cout << "-1" << endl
#define one cout << '1' << endl
#define endl "\n"
#define int long long int

#define cn(n) int n;cin >> n
#define cs(s) string s;cin >> s
#define ct(n) cout << n << endl

#define disp(a,start,end) for(int i = start; i < end; i++){cout << a[i] << " ";}cout << endl;
#define forin(a,n) for(int i = 0;i < n;i++){cin >> a[i];}
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sum(a) (accumulate ((a).begin(), (a).end(), 0LL))

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vc vector<char>
#define vb vector<bool>
#define mii map<int , int>
#define mci map<char , int>
#define pii pair<int , int>
#define pci pair<char , int>
#define umii unordered_map<int , int>
#define umci unordered_map<char , int>
#define si set<int>
#define sc set<char>
#define usi unordered_set<int>
#define usc unordered_set<char>

#define pb push_back
#define pp pop_back

using namespace std;

void add(vi &ans, int index, int n, vi arr){
    if(index == n - 1){
        ans.pb(arr[n-1]);
        int i = n - 2;
        while((i >= 0) && (arr[i] > arr[0])){
            ans.pb(arr[i]);
            i--;
        }
        for (int j = 0; j <= i; j++)
        {
            ans.pb(arr[j]);
        }
    }
    else{
        // if(indexN == 0){
        //     indexN = indexN_1;
        // }
        for (int i = index; i < n; i++)
        {
            ans.pb(arr[i]);
        }
        int i = index - 1;
        ans.pb(arr[i--]);
        while((i >= 0) && (arr[i] > arr[0])){
            ans.pb(arr[i]);
            i--;
        }
        for (int j = 0; j <= i; j++)
        {
            ans.pb(arr[j]);
            // cout << "j : " << j <<  " arr[j] : " << arr[j] << endl;
        }
    }
}

void solve()
{
    cn(n);
    vi arr(n);
    int indexN = -1, indexN_1 = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] == n) indexN = i;
        if(arr[i] == n-1) indexN_1 = i;
    }
    vi ans;

    if(indexN == n-1){
        add(ans, n - 1, n, arr);
    }
    else{
        if(indexN == 0) indexN = indexN_1;
        add(ans, indexN, n, arr);
    }
    disp(ans, 0, n);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}