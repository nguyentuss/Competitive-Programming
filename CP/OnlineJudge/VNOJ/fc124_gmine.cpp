#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ii pair<long long , long long>
#define f first
#define s second
#define ll long long

ii a[3001];
long long f[3001][3007];
bool g[3001][3007];
ll n , w;

int dp(int pos , int time) {
	if (pos > n || time >= w) return 0;
	if (g[pos][time]) return f[pos][time];
	ll val = dp(pos + 1 , time);
	val = max(val , dp(pos + 1 , time + a[pos].f) + a[pos].s);
	g[pos][time] = true;
	return f[pos][time] = val;
}

int main() {
	boost;
	//freopen("fc124_gmine.inp", "r",stdin);
	//freopen("fc124_gmine.out","w",stdout);

	cin >> n >> w;

	for (int i = 1 ; i <= n; i++) 
		cin >> a[i].f >> a[i].s;
	sort(a + 1 , a + 1 + n);
	cout << dp(1 , 0);
	return 0;
}