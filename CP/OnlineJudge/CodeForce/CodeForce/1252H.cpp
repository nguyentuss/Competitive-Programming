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
int S = 0.0;

void solve() {
    int n; cin >> n;
    vector<ii> v;
    multiset<int> s;
    int tt = 0;
    rep(i , 0 , n) {
        int l , w; cin >> l >> w;
        if (l > w) swap(l , w); 
        v.push_back(ii(l , w));
        s.insert(w);
        S = max(S , (l*w));
    }   
    sort(v.begin() , v.end());
    for (auto [l , w] : v) {
        s.erase(s.find(w));
        auto it = s.rbegin();
        if (!s.empty()) {
            int tmp = *it;
            S = max(S , 2ll * l * min(w , tmp));
        }
    }
    cout << (S / 2) << "." << 5 * (S & 1);
}

main() {
	int test = 1;
	//cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}