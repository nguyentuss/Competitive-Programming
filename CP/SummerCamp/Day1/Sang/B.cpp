#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int> 
const int MAX_N = 1e5 + 7;

int node = 0;

struct seg{
	int val , l , r;
};

int ls(int x) {
	return (x << 1);
}

int rs(int x) {
	return (ls(x) + 1);
}
seg IT[4 * MAX_N];
int a[MAX_N];

void modify(int cur) {
	IT[cur].val = max(IT[IT[cur].l].val , IT[IT[cur].r].val);
}

int build(int l , int r) {
	if (l == r) {
		++node;
		IT[node] = {a[l] , 0 , 0};
		return node; 
	}
	int mid = (l + r)>>1;
	int cur = ++node;
	IT[cur].l = build(l , mid);
	IT[cur].r = build(mid + 1 , r);
	modify(cur);
	return cur;
}

int update(int l , int r , int i , int oldNode) {
	if (l == r) {
		node++;
		IT[node] = {a[l] , 0 , 0};
		return node;
	}
	int mid = (r + l)>>1;
	int cur = ++node;
	if (i <= mid) {
		IT[cur].l = update(l , mid , i, IT[oldNode].l);
		IT[cur].r = IT[oldNode].r;
	}
	else {
		IT[cur].l = IT[oldNode].l;
		IT[cur].r = update(mid + 1 , r , IT[oldNode].r);
	}
	modify(cur);
	return cur;
}

int get(int node , int l , int r , int L , int R)

int main() {
	int n; cin >> n;
	for (int i = 1 ; i <= n ;i ++)
		cin >> a[i];
	build(1 , 1 , n);
	
	cout << node;
}