#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int a , n , k , b; cin >> a >> n >> k >> b; 
    int ans = 0;
    while (n > 0) {
        ans++;
        int tm = min(a , k + 1)*b;
        k = max(0ll , k - (a - 1));
        n -= tm;
        cerr << n << '\n';
    }
    cout << ans;
    return 0;
}