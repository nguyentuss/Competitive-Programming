#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)

struct query{
	int l , r , k , id;
};
struct ele {
	int val , id;
};

bool cmp(query &a , query &b) {
	return a.k < b.k;
}
bool cmp1(ele &a , ele &b) {
	return a.val < b.val;
}
bool cmp2(ele &a , ele &b) {
	return a.id < b.id;
}

int IT[MAX_N];
ele a[MAX_N];
query b[MAX_N];
ele res[MAX_N];

void build(int id , int left , int right) {
	if (left == right) {
		IT[id] = 1;
		return;
	}
	int mid = (left + right)/2;
	build(2*id , left , mid);
	build(2*id + 1 , mid + 1, right);
	IT[id] = IT[2*id] + IT[2*id + 1];
	return;
}

void update(int id , int left , int right , int i) {
	if (i < left || i > right) 
		return;
	if (left == right) {
		IT[id] = 0;
		return;
	}
	int mid = (left + right)/2;
	update(2*id , left , mid , i);
	update(2*id + 1, mid + 1 , right , i);
	IT[id] = IT[2*id] + IT[2*id + 1];
	return;
}

int get(int id , int left , int right , int queryL , int queryR) {
	if (left > queryR || right < queryL) return 0;
	if (queryL <= left && right <= queryR) return IT[id];
	int mid = (left + right)/2;
	return get(2*id , left , mid , queryL , queryR) +
	get(2*id + 1 , mid + 1 , right , queryL , queryR);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i].val; 
		a[i].id = i;
	}
	int q; cin >> q;
	for (int i = 1 ; i <= q ; i ++) {
		int l , r , k; cin >> l >> r >> k;
		b[i].l = l , b[i].r = r , b[i].k = k , b[i].id = i; 
	}
	sort(b + 1 , b + 1 + q , cmp);
	sort(a + 1 , a + 1 + n , cmp1);
	build(1 , 1 , n);
	int cnt = 0;
	for (int i = 1 ; i <= q ; i++) {
		//cout << b[i].l << " " << b[i].r << " " << b[i].k << '\n';
		while (cnt <= n && a[cnt].val <= b[i].k) {
			update(1 , 1 , n , a[cnt].id);
			cnt++;
		}
		res[i].val = get(1 , 1 , n , b[i].l , b[i].r);	
		//cout << res[i].val << '\n';
		res[i].id = b[i].id;
	}
	sort(res + 1 , res + 1 + q , cmp2);
	for (int i = 1 ; i <= q ; i++) 
		cout << res[i].val << '\n';
	return 0;
}