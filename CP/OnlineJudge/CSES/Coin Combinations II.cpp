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
const int N = 2e6 + 7;
const int MOD = 1e9 + 7;

// sort c[1] < c[2] < .. < c[n];
// f[i][j] la so cach su dung toi i thang va dc j money
// f[i - 1][j - c[i]] la chi dc su dung c[1] < c[2] < .. c[i - 1]

int c[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , x; cin >> n >> x;
    for (int i = 1 ; i <= n ; i++) 
        cin >> c[i];
    sort(c + 1 , c + 1 + n);
    vector<int> f(x + 1);
    f[0] = 1;
    for (int i = 1 ; i <= n ; i++) {                                                                                                                            
        for (int j = 0 ; j <= x ; j++) {
            if (j - c[i] >= 0) {
                (f[j] += f[j - c[i]])%=MOD;
            }
        } 
    }
    cout << f[x];
    return 0;
}