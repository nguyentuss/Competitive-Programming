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

string x , y;
int n , m;
string minn = "a", maxx = " ";

void sol(int i, int j, string s)
{
	if (i == x.size() && j == y.size())
	{
		if (minn > s) minn = s;
		if (maxx < s) maxx = s;
		return;
	}
	if (i < x.size()) sol(i + 1, j, s + x[i]);
	if (j < y.size()) sol(i, j + 1, s + y[j]);
}

void solve() {
    cin >> x >> y;
    n = sz(x);
    m = sz(y);
    sol(0,0, "");
    cout << minn << ' ' << maxx << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
 
}
