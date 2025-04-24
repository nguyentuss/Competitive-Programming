//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int N = 2e5 + 7;
const int M = 1e5 + 7;

int a[M];
int g[M]; 
vector<int> di[M];

int mex(vector<int>& u) {
    sort(u.begin() , u.end());
    int res = 0;
    for (int x : u) {
        if (res == x) res++;
    }
    return res;
}

int Grundy(int i) {
    if (g[i] != -1) return g[i];
    vector<int> u;
    for (int x : di[i]) {
        u.push_back(Grundy(x));
    }   
    return g[i] = mex(u);
}

void solve() {
    int n, m; cin >> n >> m;
    // for (int i = 1 ; i <= n ; i++) cin >> a[i]; 
    for (int i = 1 ; i <= n ; i++) {
        a[i] = m;
    }
    for (int i = 1 ; i < M ; i++) g[i] = -1;
    g[1] = 0;
    for (int i = 2 ; i < M ; i++) {
        di[i].push_back(1);
        for (int j = 2 ; j * j <= i ; j++) {
            if (i % j == 0) {
                if (j != i/j) {
                    di[i].push_back(j); 
                    di[i].push_back(i/j);
                }
                else {
                    di[i].push_back(j);
                }
            }
            
        }
    }
    for (int i = 2 ; i < M ; i++) sort(di[i].begin() , di[i].end()); 
    for (int i = M - 1; i >= 1 ; i--) {
        if (g[i] == -1)
            Grundy(i);
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        ans ^= g[a[i]];
    }
    if (ans > 0) cout << "Anna";
    else cout << "Bruno";
    //for (int i = 1 ; i < 20 ; i++) cout << g[i] << " ";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}