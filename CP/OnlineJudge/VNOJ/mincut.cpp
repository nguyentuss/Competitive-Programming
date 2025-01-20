#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 ;
const ll maxn = 1e3 + 7;
using namespace std;
#pragma GCC optimize("Ofast")
ll n , m , a[maxn][maxn] , f[maxn][maxn];
ll k , x , y , u , v;
ll ans;

ll get(ll x , ll y , ll u , ll v)
{
    return f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1];
}
void sol1()
{
    ll l = y ,r = v - 1 , mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        ans = min (ans , abs(get(x , y , u , mid) - get(x , mid + 1 , u , v)));
        if (get(x , y , u , mid) <= get(x , mid + 1 , u , v)) l = mid + 1;
        else r = mid - 1;
    }
    if (mid < v - 1) mid ++ , ans = min (ans , abs(get(x , y , u , mid) - get(x , mid + 1 , u , v)));
}
void sol2()
{
    ll l = x , r = u - 1 , mid;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        ans = min (ans , abs(get(x , y , mid , v) - get(mid + 1 , y , u , v)));
        if (get(x , y , mid , v) <= get(mid + 1 , y , u , v)) l = mid + 1;
        else r = mid - 1;
    }
    if (mid < u - 1) mid++ , ans = min (ans , abs(get(x , y , mid , v) - get(mid + 1 , y , u , v)));
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++) 
        {
            cin >> a[i][j];
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        }
    }
    for (int i = 1 ; i <= k ; i++)
    {
        cin >> x >> y >> u >> v;
        ans = oo;
        sol1() , sol2();
        cout << ans << '\n';
    }
}