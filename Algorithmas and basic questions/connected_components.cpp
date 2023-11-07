#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
// less<int> -> increasing order, greater<int>->decreasing order, less_equal<int> -> work as multiset
template<class key, class value = null_type, class cmp = std::less_equal<key>>
using os = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(index) -> iterator of element at x
// order_of_key(key) -> all element strictly less than key.

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ld long double
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define cout(n) cout<<n<<nl
#define pb push_back
#define F first
#define S second
#define sz(a) (ll)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0LL))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define cnt(a,x)    ( count((a).begin(), (a).end(),(x) ))
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
const ll MM = 1e9+7;
const ll MOD = 998244353;

typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef map<ll,ll> mapii;
typedef map<ll,char> mapic;
typedef map<char,ll> mapci;
typedef set<ll> seti;
typedef set<char> setc;

template <class T> istream& operator>>(istream& stream, vector<T>& v) {for (T& vi : v) {stream >> vi;}return stream;}
template <class T> ostream& operator<<(ostream& stream, vector<T>& v) {for (T& vi : v) {stream << vi<<' ';}return stream;}
ll power(ll a, ll b, ll mod) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}

void solve()
{
    ll n; cin>>n;
    vector<pair<pii,ll>> v(n);
    for(int i=0; i<n; i++)
    {
        ll a,b; cin>>a>>b;
        v[i].first.first=a;
        v[i].first.second=b;
        v[i].second=i;
    }
    sort(all(v));
    os<ll> ms;
    mapii m;
    for(int i=0; i<n; i++)
    {
        ms.insert(v[i].first.second);
    }
    vi ans(n);
    for(int i=0; i<n; i++)
    {
        ms.erase(ms.find_by_order(ms.order_of_key(v[i].first.second)));
        ans[v[i].second] = m[v[i].first.first] + ms.order_of_key(v[i].first.second+1);
        m[v[i].first.first]++;
    }
    cout(ans);

    ms.clear();
    m.clear();
    for(int i=0; i<n; i++)
    {
        m[v[i].first.first]++;
    }
    ans = vi (n);
    for(int i=0; i<n; i++)
    {
        m[v[i].first.first]--;
        ans[v[i].second] = m[v[i].first.first] + (ms.size()-ms.order_of_key(v[i].first.second));
        ms.insert(v[i].first.second);
    }
    cout(ans);
}

signed main()
{
    fastio;
    int T=1;
    // cin>>T;
    for(int ttt=1; ttt<=T; ttt++)
    {
        //cout<<"Case #"<<ttt<<": ";
        solve();
    }
    return 0;
}