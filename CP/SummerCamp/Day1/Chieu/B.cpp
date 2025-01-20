#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
#define double long double
const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;
const double esp = 1e-4;

struct seg {
    double x , y;
};

bool cmp1(seg &a , seg &b) {
    return a.x < b.x;
};

bool cmp2(seg &a , seg &b) {
    return a.y < b.y;
};

seg a[MAX_N];

int calc(int x1 , int y1 , int x2 , int y2) {
    return ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i ++) {
        double x, y; cin >> x >> y;
        a[i].x = x; a[i].y = y;
    }
    sort(a + 1 , a + 1 + n , cmp1);
    set<pair<double , double>> s1 , s2;
    int best = 1e18;
    int l = 0;
    for (int i = 1 ; i <= n ; i++) {
        double x = a[i].x , y = a[i].y;
        double d = ceil(sqrt(best));
        while (l <= i && (double) (x - (double)(a[l].x)) >= d) {
            s2.erase(ii(a[l].y , a[l].x));
            l++;
        }
        auto it1 = s2.lower_bound(ii(a[i].y - d, a[i].x));
        auto it2 = s2.upper_bound(ii(a[i].y + d , a[i].x));
        for (auto it = it1 ; it != it2 ; it++) {
            int dx = x - it->second;
            int dy = y - it->first;
            best = min(best , 1ll*dx*dx + 1ll*dy*dy);
        }
        s2.insert(ii(a[i].y , a[i].x)); 
    }
    cout << fixed << setprecision(6) << sqrt(best);
    return 0;
}