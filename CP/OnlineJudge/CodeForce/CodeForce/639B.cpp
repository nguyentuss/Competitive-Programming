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
    int n , d , h; cin >> n >> d >> h;
    int last_verti = n - h - 1; 
    int remain_distance = d - h; 
    if ((remain_distance == 0 && h == 1 && n != 2) || (h < remain_distance)) {
        cout << -1; 
        return;
    } 
    for (int i = 2 ; i <= h + 1 ; i++) {
        cout << i - 1 << " " << i << '\n';
    }
    if (remain_distance == 0) {
        for (int i = h + 2 ; i <= n ; i++) {
            cout << h << " " << i << '\n';
        }
    }
    else {
        h++;
        int cnt = last_verti;
        int pos = h + 1;
        int height_tmp = 0;
        while (cnt) {
            if (height_tmp == 0) cout << 1 << " " << pos << '\n';
            else cout << pos - 1 << " " << pos << '\n';
            height_tmp ++;
            if (height_tmp == remain_distance) height_tmp = 0;
            pos++;
            cnt--;
        }
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