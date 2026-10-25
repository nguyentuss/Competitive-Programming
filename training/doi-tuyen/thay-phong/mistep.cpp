#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll maxn =  5e5 + 7;
const ll oo = 1e18 ;
using namespace std;
ll n , k , x, t1 , t2;
vector<ll> a;

ll sol(vector<ll> &a)
{
    ll ans = 0;
    vector<ll> b(n+1, INT_MAX);
    b[0] = INT_MIN;
    for (ll x: a) 
    {
        ll vt = upper_bound(b.begin(), b.end(), x) - b.begin();
        b[vt] = x;
        ans = max(ans, vt);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> x , a.push_back(x);
    t1 = sol(a);
    reverse(a.begin() , a.end());
    t2 = sol(a);
    if (t1 == n) cout << 0;
    else cout << min(n - t1 , n - t2);
}