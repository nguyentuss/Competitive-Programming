#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

vector<int> adj[9];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >>t;
    while (t--) {
        string s; cin >> s;
        int n = s.size(); 
        for (int i = 0 ; i <= 8 ; i++) adj[i].clear();
        s = ' ' + s;
        int w , m; cin >> w >> m;
        int sum = 0;
        vector<int> f(n + 1);
        for (int i = 1 ; i <= w ; i++) {
            sum = (sum + s[i] - '0')%9;
        }
        adj[sum].push_back(1);
        int l = 1;
        for (int i = w + 1 ; i <= n ; i++) {
            sum = (sum - (s[l] - '0') + 9)%9;
            sum = (sum + s[i] - '0')%9;
            l++;
            adj[sum].push_back(l);
            //cerr << sum << " " << l << '\n';
        }
        for (int i = 1 ; i <= n ;i ++) {
            f[i] = f[i - 1] + s[i] - '0';
        }

        //cerr << "YEE";
        for (int i = 1 ; i <= m ; i++) {
            int l , r , k; cin >> l >> r >> k;
            int x_q = (f[r] - f[l - 1])%9;
            //cerr << x_q << '\n';
            //cerr << "YEE";
            bool found = false;
            vector<ii> aa;
            for (int j = 0 ; j < 9 ; j++) {
                for (int h = 0 ; h < 9 ; h++) {
                    if (((j*x_q)%9 + h)%9 == k) {
                        if (j == h) {
                            if (adj[j].size() >= 2)
                                aa.push_back(ii(adj[j][0] , adj[j][1]));
                        }
                        else {
                            if (adj[j].size() && adj[h].size()) {
                                aa.push_back(ii(adj[j][0] , adj[h][0]));
                            }
                        }
                    }
                }
                //if (found) break;
            }
            if (!aa.size()) cout << -1 << " " << -1 << '\n';
            else {
                sort(aa.begin() , aa.end());
                cout << aa[0].fi << " " << aa[0].se << '\n';
            }
        }
        //cerr << "YES";
    }
    return 0;
}