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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , x; cin >> n >> x;
    vector<int> c(n);
    for (int i = 0 ; i < n ; i++) 
        cin >> c[i];
    vector<int> f(x + 1 , inf);
    f[0] = 0; 
    int cnt = 0;
    for (int i = 0 ; i <= x ; i++) {                                                                                                                            
        for (int j = 0 ; j < n ; j++) {
            if ((i + c[j]) <= x) {
                f[i + c[j]] = min(f[i + c[j]] , f[i] + 1);
            }
        }
        // for (int j = 0 ; j <= x ; j++) {
        //     cerr << f[j] << " ";
        // }
        // cerr << '\n';
    }
    cout << (f[x] == inf ? -1 : f[x]);
    return 0;
}