#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N (ll) (2*1e5 + 7)

ll n, k , x , i , j , f[MAX_N], v[MAX_N], ans = 1; 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("group.inp","r",stdin);
	freopen("group.out","w",stdout);
	cin >> n >> k >> x;
	for (int i = 1 ; i <= n ; i++) cin >> v[i];
	sort(v + 1,v + n + 1);
	f[1]=0;
	for (int i = 2 ; i <= n ; i++)
	{
		int tmp = v[i] - v[i-1];
		f[i] = tmp/x;
		if (f[i]*x == tmp && f[i]) f[i] -= 1ll;
	}
	sort(f+2,f+n+1);
	int cnt = 1;
	while (k && cnt<=n)
	{
		cnt++;
		if (f[cnt]!=0)
		{
			if (k<f[cnt]) break;
			k-=f[cnt];
			f[cnt]=0;
		}
	}
	for (int i = 2 ; i<=n ; i++) if (f[i]) ans++;
	cout << ans; 
	return 0;
}