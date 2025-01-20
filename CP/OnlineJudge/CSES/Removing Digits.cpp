//source:: https://cses.fi/problemset/task/1637
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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n; cin >> n;
        vector<int> f(n + 1 , inf);
        f[n] = 0;
        for (int i = n ; i >= 0 ; i--) {
            int x = i;
            while (x > 0) {
                int d = x % 10; 
                x /= 10; 
                if (i - d >= 0) {
                    f[i - d] = min(f[i - d] , f[i] + 1);
                }
            }
        }
        cout << f[0];
    }
    return 0;
}