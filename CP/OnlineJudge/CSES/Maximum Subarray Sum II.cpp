#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

int a[N] , f[N];
int n , l , r; 
multiset<int> s;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l >> r;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }  
    int ans = -inf;
    for (int i = 1 ; i <= r ; i++) {
        if (i >= l) {
            s.insert(f[i - l]);
            ans = max(ans , f[i] - *s.begin());
        }
    }
    int li = 0;
    for (int i = r + 1 ; i <= n ; i++) {
        s.erase(s.find(f[li]));
        li++;
        s.insert(f[i - l]);
        ans = max(ans , f[i] - *s.begin());
        //cout << f[i] - *s.begin() << " ";
    }
    cout << ans;

    return 0;
}