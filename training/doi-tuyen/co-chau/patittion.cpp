#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 + 7)
#define int long long

int v[MAX_N];
int IT[MAX_N];
int f[MAX_N];
int sum[MAX_N];

void segmenttree(int index , int l , int r) {
	if (l == r) {
		IT[index] = v[l];
		return;
	}
	int mid = (l + r)/2;
	segmenttree(2 * index , l , mid);
	segmenttree(2 * index + 1 , mid + 1 , r);
	IT[index] = min(IT[2*index] , IT[2*index+1]);
	return;	
}

int findmin(int index , int l , int r , int L , int R) {
	if (L > r || R < l) return inf;
	if (l <= L && R <= r) return IT[index];
	int mid = (L + R)/2;
	int vLeft = findmin(2*index , l , r , L , mid);
	int vRight = findmin(2*index + 1 , l , r , mid + 1 , R);
	return min(vLeft , vRight);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("PATITION.inp","r",stdin);
	freopen("PATITION.out","w",stdout);
	int n , c; cin >> n >> c;;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}
	segmenttree(1 , 1 , n);
	for (int i = 1 ; i < c ; i++) {
		f[i] = sum[i];
	}
	f[c] = sum[c] - findmin(1 , 1 , c , 1 , n);
	for (int i = c + 1 ; i <= n ; i++) {
		int l = i - c + 1;
		f[i] = min(f[i - 1] + v[i] , f[i - c] + sum[i] - sum[i - c] - findmin(1 , l , i , 1 , n));
	}
	cout << f[n];
	return 0;
}
