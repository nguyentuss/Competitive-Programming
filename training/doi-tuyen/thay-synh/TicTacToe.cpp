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
const int N = 1e4 + 7;

int g[N];

int Grundy(int n) {
    if (g[n] != -1) return g[n]; 
    vector<bool> v(N);
    for (int i = 1 ; i <= n ; i++) {
        int x = i - 3; 
        int y = i + 2;
        if (x < 0) x = 0; 
        if (y > n) y = n; 
        v[Grundy(x)^Grundy(n-y)] = true;
    }
    for (int i = 0 ; i < N ; i++) {
        if (!v[i]) {
            return g[n] = i;
        }   
    }
}

void solve() {  
    int n; 
    for (int i = 1 ; i < N ; i++) g[i] = -1;
    for (int i = N-1 ; i > 0 ; i--) {
        if (g[i] == -1) {
            Grundy(i);
        }
    }
    while (cin >> n , n) {
        string s; cin >> s;
        s = " " + s;
        string b = s;
        bool ok = false;
        for (int i = 2 ; i <= n ; i++) {
            if (s[i] == 'X' && (s[i-1] == 'X' || s[i-2] == 'X')) {
                cout << "S\n";
                ok = true;
                break;
            } 
        }
        if (ok) continue;
        for (int i = 1 ; i <= n ; i++) {
            if (s[i] == 'X') {
                if (i - 1 > 0) b[i-1] = 'X'; 
                if (i - 2 > 0) b[i-2] = 'X'; 
                if (i + 1 <= n) b[i+1] = 'X';
                if (i + 2 <= n) b[i+2] = 'X'; 
            }
        }
        int cnt = 0;
        int ans = 0;
        for (int i = 1 ; i <= n ; i++) {
            if (b[i] == '.') {
                cnt++;
            }
            else {
                ans ^= g[cnt];
                cnt = 0;
            }
        }
        ans ^= g[cnt];
        cout << (ans > 0 ? 'S' : 'N') << '\n';
    }
    
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