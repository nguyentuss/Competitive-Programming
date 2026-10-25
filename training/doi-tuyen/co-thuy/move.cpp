#include <bits/stdc++.h>

using namespace std;

struct seg {
	int x , t; 
};

#define MAX_N (int) (10007)
#define ii pair<int ,int>
#define f first
#define s second

seg v[MAX_N];
int n;

bool check(int x) {
	vector<ii> res;
	for (int i = 1 ; i <= n ;i++) {
		int left = v[i].x - (x/v[i].t);
		int right = v[i].x + (x/v[i].t);
		res.push_back(ii(left , right));
	}
	sort(res.begin() , res.end());
	priority_queue<int , vector<int> , greater<int>> pq;
	int cnt = 0 , pos = 0;
	for (int i = 1 ; i <= n ; i++) {
		while (pos < n && i >= res[pos].f && i <= res[pos].s) {
			pq.push(res[pos].s);
			pos ++;
		}
		if (!pq.empty()) {
			if (i <= pq.top()) {
				cnt++;
			}
			pq.pop();
		}
	}
	return (cnt == n);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("move.inp","r",stdin);
	freopen("move.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ;i ++) {
		cin >> v[i].x >> v[i].t;
	}
	int l = 0 , r = 1e9 , ans = 0; 
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}