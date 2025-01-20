#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
#define imx INT_MAX
#define imn INT_MIN
#define lmx LLONG_MAX
#define lmn LLONG_MIN
#define pi pair <int, int>
#define pl pair <ll, ll>
#define vi vector <int>
#define vvi vector <vector<int>>    
#define vvvi vector <vector<vector<int>>>
#define vpi vector <pi>
#define vpl vector <pl>
#define vl vector <ll>
#define vvl vector <vector<ll>>    
#define vvvl vector <vector<vector<ll>>>  
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define endl '\n'
#define nl cout << '\n' 
#define pb push_back
#define eb emplace_back
#define em emplace
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define p(x) cout << x << '\n'
#define ps(x) cout << x << " "
#define sz(x) (ll)(x).size()
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define lb(x, key) lower_bound(all(x), key)
#define ub(x, key) upper_bound(all(x), key)
#define rall(x) x.rbegin(), x.rend()
#define initialize(a, i) memset(a, i, sizeof(a))
#define F0R(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define RF0R(i, n) for (ll i = n - 1; i >= 0; i--)
#define RFOR(i, a, b) for (ll i = a; i >= b; i--)
#define trav(it, a) for (auto &it : a)
#define db(x) debug(x)
using namespace std;


void calculateSubtreeSize(ll node, vl &subSz, vl adj[])
{
    subSz[node] = 1;

    trav (child, adj[node])
    {
        calculateSubtreeSize(child, subSz, adj);
        subSz[node] += subSz[child];
    }
}

ll teams;

void DFS (ll node, ll k, vl &subSz, vl adj[])
{
    teams += (k > 0);

    ll ply = 0;

    trav (it, adj[node])
        ply += subSz[it];

    trav (child, adj[node])
    {
        ll K = (node == 1 || !k) ? k + ply - subSz[child] : k + ply - subSz[child] - 1;
        DFS(child, K, subSz, adj);
    }
}

void solve()
{
    teams = 0;

    ll n;
    cin >> n;

    vl adj[n + 1];

    FOR (i, 2, n)
    {
        ll p;
        cin >> p;
        adj[p].eb(i);
    }

    vl subSz(n + 1, 0);
    calculateSubtreeSize(1, subSz, adj);

    DFS(1, 0, subSz, adj);

    p(teams/2);
}

signed main() 
{
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif

    // clock_t begin = clock();
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    cin >> t;

    while (t--)
        solve();
        
    // printf("%.3lf seconds\n", (double) (clock() - begin) / CLOCKS_PER_SEC);
    
	return 0;
}