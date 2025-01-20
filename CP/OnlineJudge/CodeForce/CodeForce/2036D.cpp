//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n , vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m ; j++) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }
    }
    int ans = 0;
    for (int k = 0; k < min(n, m) / 2; k++){
        string s = "";
        int top = k, left = k, down = n - 1 - k, right = m - 1 - k;
        for (int i = left; i <= right; i++) {
            char c = a[top][i] + '0'; 
            s += c;
        }
        for (int j = top + 1; j <= down; j++) {
            char c = a[j][right] + '0';
            s += c;
        }
        if (down != top){
            for (int i = right - 1; i >= left; i--)
            {
                s += a[down][i] + '0';
            }
        }
        if (left != right)
        {
            for (int j = down - 1; j >= top + 1; j--)
            {
                s += a[j][left] + '0';
            }
        }
        string temp = s;
        if (s.size() >= 3){
            temp += s.substr(0, 3);
        }
        else{
            temp += s;
        }
        for (int i = 0; i <= sz(temp) - 4; i++)
        {
            if (temp.substr(i, 4) == "1543")
            {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}