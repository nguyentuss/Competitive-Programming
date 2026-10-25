#include <bits/stdc++.h>
using namespace std;

int f[2007][2007];
int a[2007];


int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int test;
	cin >> test;
	while (test--)
	{
		int n,m;
		cin >> n >> m;
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 0 ; j <= m ; j++) {
				f[i][j] = 0;
			}
		}
		for (int i=1;i<=n;i++) 
			cin >> a[i];
		for (int i=1;i<=m;i++)
			f[1][i]=(a[1]<=i)*a[1];
		for (int i=1;i<=n;i++)
			for (int v=0;v<=m;v++)
				if (a[i]>v) f[i][v]=f[i-1][v];
				else f[i][v]=max(f[i-1][v],f[i][v-a[i]]+a[i]);
		cout << f[n][m] << "\n";
	}
}