//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repn(i ,a, b) for(int i = a; i <= (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    set<ii> s;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        s.insert({a[i] , i});
    }
    int ans = 1;
    auto [curr , pos] = *s.begin();
    int op = 1 , max_op = 1;
    int tmp_pos = pos;
    s.erase(s.begin());
    while (!s.empty()) {
        for (auto [x , cur_pos] : s) {
            if (x != curr) {
                curr = x;
                tmp_pos = pos;
                op = max_op;
                if (pos > tmp_pos) {
                    max_op++;
                }
            }
            else {
                if (tmp_pos > cur_pos) {
                    
                }
                else {
                    ans += op;
                    if (op == max_op) pos = cur_pos;
                }
            }
        }
    }
}

main() {
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}