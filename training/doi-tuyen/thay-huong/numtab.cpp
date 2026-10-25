#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3*1e5 + 7)
#define MAX_NUM (int) (1e6 + 7)
#define int long long

int a[MAX_N];
int IT[4*MAX_N];
int f[MAX_NUM];

void eratosthenes() {
	for (int i = 1 ; 2*i < MAX_NUM ; i++) {
		f[i] ++;
		int j = i + i;
		while (j < MAX_NUM) {
			f[j]++;
			j += i;
		}
	}
}

int get(int id , int l , int r , int ql , int qr) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return IT[id];
	int mid = (l + r) /2;
	return (get(2*id , l , mid , ql , qr) + get(2*id + 1 , mid + 1 , r , ql , qr));
}

void update(int id , int l , int r , int i , int x) {
	if (l > i || r < i) return;
	if (l == r) {
		IT[id] = x;
		return;
	}
	int mid = (l + r)/2;
	update(2*id , l , mid , i , x);
	update(2*id + 1 , mid + 1 , r , i , x);
	IT[id] = IT[2*id] + IT[2*id + 1];
}

void build(int id , int l , int r) {
	if (l == r) {
		IT[id] = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(2*id , l , mid);
	build(2*id + 1 , mid + 1 , r);
	IT[id] = IT[2*id] + IT[2*id + 1];
	return;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("numtab.inp","r",stdin);
	freopen("numtab.out","w",stdout);
	eratosthenes();
	//cout << f[1000000];
	int n , q; cin >> n >> q;
	for (int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	build(1 , 1 , n);
	set<int> s;
	for (int i = 1 ; i <= n ; i++) {
		if (a[i] != 1 && a[i] != 2) s.insert(i);
	} 
	int pos;
	for (int i = 1 ; i <= q ; i++) {
		int ask , l , r; cin >> ask >> l >> r;
		if (ask == 1) {
			pos = l;
			while (pos <= r) {
					auto it = s.lower_bound(pos);
					if (it == s.end() || *it > r) break;
					else {
						a[*it] = f[a[*it]];
						update(1 , 1 , n , *it , a[*it]);
						if (a[*it] == 1 || a[*it] == 2) s.erase(it);
						pos = *it + 1;
					}
			}
		}
		else {
			cout << get(1 , 1 , n , l , r) << '\n';
		}
	}
	return 0;
}