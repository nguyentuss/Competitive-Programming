//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

#define ii pair<int , int>

struct sg {
    int a , b;
};


void solve() {
    int n, k; cin >> n >> k;
    vector<sg> a(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].a;
    }
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].b; 
    }
    sort(a.begin() + 1 , a.end(), [](sg &a , sg &b) {
        if (a.a == b.a) return a.b < b.b; 
        return a.a < b.a;
    });
    priority_queue<int , vector<int> , greater<int>> pq;
    int ans = 0;
    int s = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (a[i].a < a[i].b) {
            s -= a[i].a; 
            pq.push(a[i].b); 
            while (pq.size() > k) s += pq.top(), pq.pop();
            ans = max(ans , s); 
        }
    }
    cout << ans << '\n';
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}