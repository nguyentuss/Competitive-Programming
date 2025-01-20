#include <bits/stdc++.h>

using namespace std;

#define ii pair<double , double>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
const double esp = 1e-6;

struct node{
    int x , y , time;
};

node a[N];
pair<double , double> f[mask][15];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<node> a(n + 1);
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i].x >> a[i].y >> a[i].time;
        }
        double m; cin >> m;
        auto distance = [&](int i , int j) -> double {
            int x1 = a[i].x; int y1 = a[i].y;
            int x2 = a[j].x; int y2 = a[j].y;
            return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        };

        auto ok = [&](double velo) -> bool {
            vector<vector<ii>> f(1 << n , vector<ii>>(n , {0 , 0}));
            f[0][0] = {0 , velo};
            for (int mask = 0 ; mask < (1 << n) ; mask++) {
                for (int i = 0 ; i < n ; i++) {
                    auto cur = f[mask][i];
                    if (cur == {0 , 0}) continue;
                    for (int j = 0 ; j < n ; j++) {
                        if (mask & (1 << j) == 0) {
                            double dist = distance(i , j);  
                            if (cur.fi + dis/cur.se <= a[i].time) {
                                f[mask | (1 << j)][j] = min(f[mask | (1 << j)][j] , {cur.fi + dis/cur.se , cur.se*m});
                            }
                        }
                    }
                }
            }

            for (int i = 0 ; i < n ; i++) {
                if (f[mask][i] != {0 , 0}) return true;    
            }
            return false;
        };
        double l = 1 , r = 1e18;
        double ans;
        while (r - l > esp) {
            double mid = (l + r)/2;
            if (ok(mid)) {
                r = mid;
                ans = mid;
            }
            else l = mid;
        }
    }
    return 0;
}