#include <bits/stdc++.h>
using namespace std;

int f[107][107];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("robot.INP","r",stdin);
	freopen("robot.OUT","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) cin >> f[i][j];
	for (int i=1;i<m;i++) 
		f[0][i]+=f[0][i-1];
	for (int i=1;i<n;i++) 
		f[i][0]+=f[i-1][0];
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
			f[i][j]+=min(f[i-1][j],f[i][j-1]);
	cout << f[n - 1][m -1];
	return 0;
}