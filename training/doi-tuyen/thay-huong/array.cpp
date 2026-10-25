#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define int long long

struct asked {
	int l , r , id;
};

struct answer {
	int res , id;
};

int a[MAX_N];
vector<asked> query;
vector<answer> res;
int cnt[1000007];
int BLOCK , ans = 0;

bool cmp(asked &a , asked &b) {
	return ((a.l/BLOCK < b.l/BLOCK) || (a.l/BLOCK == b.l/BLOCK && a.r/BLOCK < b.r/BLOCK));
}

bool cmp1(answer &a , answer &b) {
	return a.id < b.id;
}

void calc1(int i) {
	ans += cnt[a[i]]*cnt[a[i]]*a[i] - (cnt[a[i]] + 1)*(cnt[a[i]] + 1)*a[i];
}

void calc2(int i) {
	ans += cnt[a[i]]*cnt[a[i]]*a[i] - (cnt[a[i]] - 1)*(cnt[a[i]] - 1)*a[i];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	freopen("array.inp","r",stdin);
	freopen("array.out","w",stdout);
	int n , q; cin >> n >> q;
	BLOCK = sqrt(n);
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for (int i = 1 ; i <= q ; i++) {
		int l , r; cin >> l >> r;
		query.push_back({l , r , i});
	}
	sort(query.begin() , query.end() , cmp);
	int currL = query[0].l , currR = query[0].r;
	for (int i = currL ; i <= currR ; i++) {
		cnt[a[i]]++;
		calc2(i);
	}
	for (auto x : query) {
		int l = x.l , r = x.r;
		while (currL < l) {
			cnt[a[currL]] --;
			calc1(currL);
			currL ++;
		}
		while (currL > l) {
			currL --;
			cnt[a[currL]]++;
			calc2(currL);
		}
		while (currR < r) {
			currR++;
			cnt[a[currR]]++;
			calc2(currR);
		}
		while (currR > r) {
			cnt[a[currR]] --;
			calc1(currR);
			currR --;
		}
		res.push_back({ans , x.id});
	}
	sort(res.begin() , res.end() , cmp1);
	for (auto x : res) {
		cout << x.res << '\n';
	}
	return 0;
}