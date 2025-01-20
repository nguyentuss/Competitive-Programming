#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)

struct seg {
	int val;
	int lazy;
};

int n;
int v[MAX_N];
seg IT[4*MAX_N];
int L[MAX_N] , R[MAX_N];

void down(int id) {
	int x = IT[id].lazy;
	IT[2*id].lazy = max(IT[2*id].lazy , x);
	IT[2*id].val = max(IT[2*id].val , x);
	IT[2*id + 1].lazy = max(IT[2*id + 1].lazy , x);
	IT[2*id + 1].val = max(IT[2*id + 1].val , x);
	IT[id].lazy = 0;	
}

void update(int id , int l , int r , int u , int v , int x) {
	if (v < l || r < u) {
		return;
	}
	if (u <= l && r <= v) {
		IT[id].val = max(IT[id].val , x);
		IT[id].lazy = max(IT[id].lazy , x);
		return;
	}
	down(id);
	int mid = (l + r)/2;
	update(2*id , l , mid , u , v , x);
	update(2*id + 1 , mid + 1 , r , u , v , x);
	IT[id].val = max(IT[2*id].val , IT[2*id + 1].val);
}

int get(int id , int l , int r , int i) {
	if (i < l || i > r) return 0;
	if (l == r)  return IT[id].val;
	down(id);
	int mid = (l + r)/2;
	return max(get(2*id , l , mid , i) , get(2*id + 1 , mid + 1 , r , i));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n; i++) {
		cin >> v[i];
	}
	deque<int> dq;
	dq.push_back(0);
	for (int i = 1 ; i <= n ; i++) {
		while (dq.size() && v[dq.back()] >= v[i]) 
			dq.pop_back();
		if (dq.size()) L[i] = dq.back() + 1;
		else L[i] = i;
		dq.push_back(i);
	}
	while (dq.size()) dq.pop_back();
	dq.push_back(n + 1);
	for (int i = n ; i >= 1 ; i--) {
		while (dq.size() && v[dq.back()] >= v[i]) 
			dq.pop_back();
		if (dq.size()) R[i] = dq.back() - 1;
		else R[i] = i;
		dq.push_back(i);
	}
	for (int i = 1 ; i <= n ; i++) {
		cout << L[i] << " " << R[i] << '\n';
		int l = 1 , r = R[i] - L[i] + 1;
		update(1 , 1 , n , l , r , v[i]);
	}
	for (int i = 1 ; i <= n ; i++) {
		cout << get(1 , 1 , n , i) << " ";
	}
	return 0;
}