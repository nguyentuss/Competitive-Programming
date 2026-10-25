#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (500007)
#define MAX_NUM (int) (1e7 + 7)
#define ii pair <int , int>

int n , k;
vector <int> v(MAX_N);
int m[10007];
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("seqmodk.inp","r",stdin);
	freopen("seqmodk.out","w",stdout);
	cin >> n >> k;
	for (int i = 0 ; i <= k ; i++) {
		m[i] = MAX_NUM;
	}
	for (int i = 1 ; i <= n ; i++) 
		cin >> v[i];
	long long s = 0;
	int ans = -1 , pos = 0;
	m[0] = 0;
	for (int i = 1 ; i <= n ;i++) {
		s = (s + v[i])%k;
		if (m[s] != MAX_NUM && ans < (i - m[s])) {
			ans = max(ans , i - m[s]);
			pos = m[s] + 1;
		}
		m[s] = min(m[s] , i);
	}
	cout << ans << " " << pos;
	return 0;
}