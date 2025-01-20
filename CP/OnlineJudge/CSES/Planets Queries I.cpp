//source:: https://cses.fi/problemset/task/1750/
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

int P[N][32];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        int n , q; cin >> n >> q;
        for (int i = 0 ; i < n ; i++) {
            for (int k = 0 ; k < 32 ; k++) {
                P[i][k] = -1;
            }
        }
        for (int i = 0 ; i < n ; i++) {
            int x; cin >> x;
            x--;
            P[i][0] = x;;
        }
        for (int k = 1 ; k < 32 ; k++) {
            for (int i = 0 ; i < n ; i++) {
                if (P[i][k - 1] != -1) {
                    P[i][k] = P[P[i][k - 1]][k - 1];
                }
            }
        }
        while (q--) {
            int u, k; cin >> u >> k;
            u--;
            if (k == 0) {
                cout << u + 1 << '\n';
                continue;
            }
            int ans = -1;
            while (true) {
                bool found = false;
                for (int i = 0 ; i < 32 ; i++) {
                    if ((1 << i) == k) {
                        ans = P[u][i];
                        found = true; 
                        break;
                    }
                    if ((1 << i) > k) {
                        u = P[u][i - 1];
                        k = k - (1 << (i - 1));
                        break;
                    }
                }
                if (found) break;
            }
            cout << ans + 1 << '\n';
        }
    }
    return 0;
}