//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> f(n) , a(n);
        for (int i = 0 ; i < n ; i++) cin >> a[i];
        sort(a.begin() , a.end());
        f[0] = 0;
        f[1] = a[1] - a[0];
        f[2] = a[2] - a[0];
        for (int i = 3 ; i < n ; i++) {
            f[i] = min(f[i - 1] , f[i - 2]) + a[i] - a[i - 1];
        }
        cout << f[n - 1];
    }
    return 0;
}