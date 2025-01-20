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
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;
const int W = 1e5 + 7;

int h[N];
int s[N]; 

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , x; cin >> n >> x;
    for (int i = 1 ; i <= n ; i++) cin >> h[i];
    for (int i = 1 ; i <= n ; i++) cin >> s[i]; 
    vector<int> f(x + 1) , g(x + 1);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= x ; j++) {
            f[j] = g[j];
            if (j - h[i] >= 0) {
                f[j] = max(f[j] , g[j - h[i]] + s[i]);
            }
        }
        g = f; 
        f = vector<int> (x + 1);
    }
    cout << g[x];
    return 0;
}