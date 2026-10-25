#include <bits/stdc++.h>

using namespace std;

#define ii pair<ll ,ll>
#define MAX_N (ll) (3e3 + 7)
#define s second
#define f first
#define ll long long

ii a[MAX_N];
ll f[MAX_N][MAX_N];
ll n;
ll d[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("tienphat.inp","r",stdin);
	freopen("tienphat.out","w",stdout);
	cin >> n;
	for (ll i = 1 ; i <= n ;i++) {
		cin >> a[i].f >> a[i].s;
	}
	sort(a + 1 , a + 1 + n);
	f[1][1] = a[1].s;
	for (int i=2;i<=n;i++)
	{
		f[i][1]=f[i-1][1]+a[i].f-a[1].f;
		d[i]=f[i][1];
	}
	f[2][2] = a[1].s + a[2].s;	
	d[1] = a[1].s;
	d[2] = min(f[2][1] , f[2][2]);
	for (int i = 3 ; i <= n ;i++) {
		for (int j = 1 ; j < i ; j++) {
			f[i][j] = f[i - 1][j] + a[i].f - a[j].f;
			d[i] = min(d[i] , f[i][j]);
		}
		f[i][i] = d[i - 1] + a[i].s;
		d[i] = min(d[i] , f[i][i]);
	}
	cout << d[n];
	return 0;
}