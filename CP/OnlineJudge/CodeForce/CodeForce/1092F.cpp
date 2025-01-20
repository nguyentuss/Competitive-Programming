#include <bits/stdc++.h>

using namespace std;

#define MAX_N (long long ) (2e5 + 7)

long long  n , x , y;

vector <long long> sum(MAX_N );
vector <long long > arr[MAX_N];
vector <long long > a(MAX_N);
long long fdown[MAX_N] = {LLONG_MIN};
long long fup[MAX_N] = {LLONG_MIN};

void DFSdown(long long  u , long long  father) {
	sum[u] = a[u];
	for (long long  i = 0 ; i < (long long ) arr[u].size() ; i++) {
		long long  v = arr[u][i];
		if (v == father) continue;
		DFSdown(v,u);
		sum[u] += sum[v];
		fdown[u] += fdown[v] + sum[v];
	}
}

void DFSup(long long  u , long long  father) {
	for (long long  i = 0 ; i < (long long ) arr[u].size() ; i++) {
		long long  v = arr[u][i];
		if (v == father) continue;
		fup[v] = fdown[u] - fdown[v] - 2*sum[v] + fup[u] + sum[1];
		DFSup(v ,u);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (long long  i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for (long long  i = 0 ; i < n - 1 ; i++) {
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	DFSdown(1 , -1);
	DFSup(1 , -1);

	long long ans = LLONG_MIN;
	for (long long  u = 1 ; u <= n ; u++) {
		ans = max(ans , fup[u] + fdown[u]);
	}
	cout << ans;

	return 0;
}