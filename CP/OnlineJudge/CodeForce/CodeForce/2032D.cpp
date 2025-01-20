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
    int n; cin >> n;
    vector<int> p(n);
    bool stat = 0;
    vector<int> vl;
    p[1] = 0;
    int tm = 1;
    int ask = 0;
    vector<int> vcl(n);
    for (int i = 2 ; i < n ; i++) {
        cout << "? " << 1 << " " << i << endl;
        ask++;
        int x; cin >> x;
        if (!x) {
            vcl[i] = true;
            vl.push_back(i);
            p[i] = tm;
            tm = i;
        }
    }
    auto write = [&]() -> void{
        cerr << ask << " " << 2*n - 6 <<'\n';
        cout << "! ";
        for (int i = 1 ; i < n ; i++) cout << p[i] << " ";
        cout << endl;
    };
    int l = 0 , r = vl[0] + 1;
    for (int j = 2 ; j < vl[0] ; j++) {
        if (!l) l = j;
        p[j] = 0;
    }
    if (!l || l == r || r >= n) {
        write();
        return;
    }
    // cerr << l << " " << r << '\n';
    vector<bool> isRepeat(n);
    for (int i = 0 ; i < sz(vl) ; i++) {
        if (i == sz(vl) - 1) {
            if (r >= n) {
                write();
                return;
            }
            int prev = l;
            for (int j = r ; j < n ; j++) {
                while (l < n) {
                    if (vcl[l]) {
                        l++;
                        continue;
                    }
                    cout << "? " << j << " " << l << endl;
                    ask++;
                    int x; cin >> x;
                    if (!x) {
                        if (isRepeat[l]) {
                            for (int k = j ; k < n ; k++) {
                                p[k] = k - 1;
                            }
                            write();
                            return;
                        }
                        isRepeat[l] = true;
                        p[j] = l;
                        prev = j;
                        break;
                    }   
                    else l++; 
                }
            }
            // cout << prev << " " << n << '\n';
            write();
            return;
        }
        else {
            for (int j = r ; j < vl[i + 1] ; j++) {
                while (l < vl[i]) {
                    cout << "? " << j << " " << l << endl;
                    ask++;
                    int x; cin >> x;
                    if (!x) {
                        p[j] = l;
                        l++; 
                        break;
                    }
                    l++;
                }
            }
        }
        l = vl[i] + 1;
        r = vl[i + 1] + 1;
        if (r >= n || l >= n) {
            write();
            return;
        }
    }
    write();
    assert(ask <= 2*n - 6);
    return;
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