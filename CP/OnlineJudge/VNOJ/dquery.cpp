#include <bits/stdc++.h>

using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define MAX_N (int) (3e4 + 7)
#define MAX_NUM (int) (1e6 + 7)
#define ii pair<int ,int>

struct seg {
	int l , r , id;
};

vector <int> v(MAX_N);
vector <int> cnt(MAX_NUM);
vector <seg> query;
int BLOCK;

bool cmp(seg &a , seg &b) {
	return ((a.l/BLOCK < b.l/BLOCK) || (a.l/BLOCK == b.l/BLOCK && a.r/BLOCK < b.r/BLOCK));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	BLOCK = sqrt(n);
	for (int i = 1 ; i <= n; i++) 
		cin >> v[i];
	int q; cin >> q;
	for (int i = 1 ; i <= q ; i++) {
		int l , r; cin >> l >> r;
		query.push_back({l , r , i});
	}
	sort(query.begin() , query.end() , cmp);
	for (auto x : query) {
		cout << x.l << " " << x.r << '\n';
	}
	int currL = 0 , currR = 0 , diff = 0;
	vector <ii> res;
	//res.push_back(ii(query[0].id , diff));
	for (int i = 0 ; i < q ; i++) {
		int L = query[i].l , R = query[i].r;
		while (currL < L) {
			cnt[v[currL]] --;
			if (!cnt[v[currL]]) diff--;
			currL++;
		}
		while (currL > L) {
			currL --;
			if (!cnt[v[currL]]) diff++;
			cnt[v[currL]] ++;
		}
		while (currR < R) {
			currR++;
			if (!cnt[v[currR]]) diff++;
			cnt[v[currR]] ++;
		}
		while (currR > R) {
			cnt[v[currR]] --;
			if (!cnt[v[currR]]) diff--;
			currR--;
		}
		res.push_back(ii(query[i].id , diff));
	}
	sort(res.begin() , res.end());
	for (ii e : res) cout << e.second << '\n';
	return 0; 
}