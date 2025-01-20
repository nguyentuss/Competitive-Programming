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
const int N = 5e5 + 7;
const int MOD = 1e9 + 7;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

struct seg {
    int x , y , id;
};
void solve() {
    int n; cin >> n;
    UF uf(n);
    vector<seg> a(n); 
    vector<int> pos(2*n + 3);
    int cc = 0; 
    for (auto &[x , y , id] : a) {
        cin >> x >> y , id = cc++;
        pos[y] = id;
    }
    sort(a.begin() , a.end() , [&](const seg a , const seg b) {
        return a.x < b.x;
    });
    set<int> s;
    int ed = 0;
    for (auto [x , y , id] : a) {
        auto it = s.lower_bound(x); 
        while (it != s.end() && *it <= y) {
            uf.join(pos[*it] , pos[y]);
            ed++;
            if (ed > (n - 1)) {
                cout << "NO"; 
                return;
            }
            it++;
        }
        s.insert(y);
    }
    if (uf.size(0) == n && ed == n - 1) cout << "YES";
    else cout << "NO";
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}