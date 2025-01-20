//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(a) (int) a.size()

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

struct seg {
    int l , r , d;
};

int m , n , k , t; 
int a[N];
seg b[N];

bool check(int X) {
    int R = 0;
    int cnt = 0;
    int L = 0;
    vector<ii> v;
    bool status = false;
    int time = n + 1;
    for (int i = 0 ; i < k ; i++) {
        if (b[i].d > X) {
            if (b[i].l > R) {
                if (status)
                    time = time + 2*(R - L + 1);
                L = b[i].l;
            }
            R = max(R , b[i].r);
            status = true;
        }
    }
    if (R && L)
    time = time + 2*(R - L + 1);
    //cerr << time << '\n';
    return (time <= t);
}


void solve() {
    cin >> m >> n >> k >> t;
    for (int i = 0 ; i < m ; i++) {
        cin >> a[i];
    }
    sort(a , a + m);
    for (int i = 0 ; i < k ; i++) {
        cin >> b[i].l >> b[i].r >> b[i].d; 
    }
    sort(b , b + k , [](seg &x , seg &y) {
        if (x.l == y.l) return (x.r > y.r); 
        return x.l < y.l;
    });
    // for (int i = 0 ; i < k ; i++) {
    //     cout << b[i].l << " " << b[i].r << " " << b[i].d << '\n';
    // }
    a[m] = inf;
    int l = 0 , r  = m;
    int mx = 0;
    while (l <= r) {
        int mid = (l + r)/2; 
        //cerr << l << " " << r << " " << mid << '\n';
        if (check(a[mid])) {
            r = mid - 1;
            mx = a[mid];
        }
        else l = mid + 1;
    }
    int ans = 0;
    for (int i = 0 ; i < m ; i++) {
        if (a[i] >= mx) ans++;
    }
    cout << ans << '\n';
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	//cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}