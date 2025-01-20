#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()
#define rep(i , a , b) for (int i = a ; i < b ; i++)
typedef vector<int> vi;

const int N = 1e5 + 7;
const int inf = 1e18;

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true
 
	TwoSat(int n = 0) : N(n), gr(2*n) {}
 
	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}
 
	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }
 
	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}
 
	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}
 
	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void solve() {
    int n , m; cin >> m >> n;
    TwoSat ts(n);
    for (int i = 0 ; i < m ; i++) {
        char ch_u , ch_v;
        int u , v; 
        cin >> ch_u >> u >> ch_v >> v;
        u--; v--;
        if (ch_u == '-') u = ~u;
        if (ch_v == '-') v = ~v;
        ts.either(u , v);
    }
    if (ts.solve()) {
        for (int i = 0 ; i < n ; i++) {
            cout << (ts.values[i]?"+":"-") << ' ';
        }
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}