#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (4*5e4 + 7)

struct seg {
	int val;
	int lazy;
};

seg IT[MAX_N];
int n , m;

void down(int id) {
	int x = IT[id].lazy;
	IT[2*id].lazy += x;
	IT[2*id].val += x;
	IT[2*id + 1].lazy += x;
	IT[2*id + 1].val += x;
	IT[id].lazy = 0;
}

void update(int id , int l , int r , int queryL , int queryR , int x) {
	if (r < queryL || l > queryR) return;
	if (queryL <= l && r <= queryR) {
		IT[id].val += x;
		IT[id].lazy += x;
		return;
	}
	down(id);
	int mid = (l + r)/2;
	update(2*id , l , mid , queryL , queryR , x);
	update(2*id + 1 , mid + 1 , r , queryL , queryR , x);
	IT[id].val = max(IT[2*id].val , IT[2*id + 1].val);
	return ;
}

int get(int id , int l , int r , int queryL , int queryR) {
	if (r < queryL || l > queryR) return 0;
	if (queryL <= l && r <= queryR) return IT[id].val;
	down(id);
	int mid = (l + r)/2;
	return max(get(2*id , l , mid , queryL , queryR) ,
		get(2*id + 1 , mid + 1 , r , queryL , queryR));

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m ; i++) {
		int q , x , y , k;
		cin >> q;
		if (q == 0) {
			cin >> x >> y >> k;
			update(1 , 1 , n , x , y , k);
		}
		else {
			cin >> x >> y;
			cout << get(1 , 1 , n , x , y) << '\n';
		}
	}
	return 0;
}