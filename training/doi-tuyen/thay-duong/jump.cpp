#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
int k , n;
vector<int> v;
int IT[4*MAX_N];
int findmax(int l , int r , int L , int R , int index) {
	if (l > R || r < L) return 0;
	if (L <= l && r <= R) return IT[index];
	int mid = (l + r)/2;
	int v1 = findmax(l , mid , L , R , 2*index);
	int v2 = findmax(mid + 1 , r  , L , R , 2*index + 1);
	return max(v1 , v2);
}

void update(int l , int r , int i , int value , int index) {
	if (l > i || r < i) return;
	if (l == r) {
		IT[index] = value;
		return;
	}
	int mid = (l + r)/2;
	update(l , mid , i , value , 2*index);
	update(mid + 1 , r , i , value , 2*index + 1);
	IT[index] = max(IT[2*index] , IT[2*index + 1]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	cin >> k >> n;
	for (int i = 1 ; i <= n ;i++) {
		int x; cin >> x;
		update(1 , n , x , 1 , 1);
	}	
	for (auto x : v) {
		int c = findmax(1 , n , 1 , x - k , 1);
		update(1 , n , x , c + 1 , 1);
	}
	cout << IT[1];
	return 0;
}