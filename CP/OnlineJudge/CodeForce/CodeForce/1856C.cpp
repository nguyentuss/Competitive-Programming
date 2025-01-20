#include <bits/stdc++.h>
#define ld long double
#define ll long long int
#define st first
#define nd second
#define pb push_back
#define pii pair<int,int>
#define mp make_pair

using namespace std;


const int N = 1005;
int n, k;
ll a[N];

bool can(int id, ll what, int ops){
    if(id > n) return false;
    if(ops < 0) return false;
    ll used = max(0LL, what - a[id]);
    if(a[id] >= what) return true;
    return can(id + 1, what - 1, ops - used);
}

void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll lo = 0;
        ll hi = 1e9;
        while(lo < hi){
            ll mid = (lo + hi + 1) / 2;
            if(can(i, mid, k)) lo = mid;
            else hi = mid - 1;
        }
        ans = max(ans, lo);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
