#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int t;

	cin >> t;

	int cnt = 0;
    vector<int> V[1 << 12];
    vector<int> G[1 << 12];
    for (int mask = 0 ; mask < (1 << 12) ; mask++) {
        for (int i = 0 ; i < 12 ; i++) {
            if ((mask & (1 << i))) G[mask].push_back(i);
            if ((mask & (1 << i)) == 0) V[mask].push_back(i);
        }
    }

	while (t--) {
		vector<int> a(12);

		for (int &u: a) {
			cin >> u;
		}

		sort(a.begin(), a.end());
		vector<tuple<int, int, int>> res;
        vector<int> f(1 << 12 , 0);
        vector<int> g(1 << 12 , 0);
        g[0] = 1;
        for (int o = 0 ; o < 4 ; o++) {
            for (int mask = 0 ; mask < (1 << 12) ; mask++) {
                if (!g[mask]) continue;
                for (int i = 2 ; i < (int) V[mask].size() ; i++) {
                    for (int u = 0 ; u + 1 < i ; u++) {
                        for (int v = u + 1 ; v < i ; v++) {
                            if (V[mask].size() < 3) continue;
                            int x = V[mask][i] , y = V[mask][u] , z = V[mask][v];
                            if (a[x] < a[y] + a[z]) {
                                int bs = (1 << x) | (1 << y) | (1 << z);
                                if (!(mask & bs)) {
                                    f[mask | bs] = 1;
                                }           
                            }
                        }
                    }
                }
            }
            g = f;
            g[0] = 1; 
            f = vector<int>(1 << 12 , 0);
        }
        int ans = 0;
        int maxi = 0; 
        int trace = 0;
        for (int mask = 0 ; mask < (1 << 12) ; mask++) {
            int one = __builtin_popcount(mask);
            if (g[mask] && one > ans) {
                ans = one;
                trace = mask;
            }
        }
		cout << "Case " << "#" << ++cnt << ": " << ans / 3 << "\n";
        //cerr << trace;
        while (trace != 0) {
            bool found = false;
            for (int i = 2 ; i < (int) G[trace].size() && !found; i++) {
                for (int u = 0 ; u + 1 < i && !found; u++) {
                    for (int v = u + 1 ; v < i && !found ; v++) {
                        if (G[trace].size() < 3) continue;
                        int x = G[trace][i] , y = G[trace][u] , z = G[trace][v];
                        if (a[x] < a[y] + a[z]) {
                            int bs = (1 << x) | (1 << y) | (1 << z);
                            if (g[trace ^ bs] == 1 && ((trace & bs) == bs)) {
                                trace ^= bs;
                                found = true;
                                cout << a[x] << " " << a[y] << " " << a[z] << '\n';
                                //cerr << trace << '\n';
                            }           
                        }
                    }
                }
            }
        }
	}
	return 0;
}