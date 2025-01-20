#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("bosotgcan.inp","r",stdin);
#define fo freopen("bosotgcan.out","w",stdout);
#define ll long long
#define mod (ll)(1e9+7)
#define div2 (ll)(500000004)
#define div6 (ll) (166666668)
#define maxn (ll)(1e7+5)
ll dem[maxn] = {0} , maximum = LLONG_MIN ,ans = 0, lower[maxn];
ll factorial3(ll p){
  return p%mod*(p-1)%mod*(p-2)%mod*div6%mod;
}

ll factorial2(ll p){
  return p%mod*(p-1)%mod*div2%mod;
}


int main() {
    boost;
    fi;fo;
    ll n , x ; cin >> n;
    for (ll i = 0 ; i < n; i++){
        cin >> x;
        dem[x] ++;
        maximum = max(maximum,x);
    }
    lower[0] = 0;
    for (ll i = 1 ; i <= maximum ; i++)
        lower[i] = lower[i-1] + dem[i];

    for (ll i = 1 ; i <= maximum ; i++) {
        ans += factorial2(dem[i])*((lower[min(2*i - 1,maximum)] - dem[i])%mod) + factorial3(dem[i])%mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}