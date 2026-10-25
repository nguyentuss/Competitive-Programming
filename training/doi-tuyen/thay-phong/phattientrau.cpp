#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define x first
#define c second	

bool cmp (ii a,ii b) {return a.x<b.x;}

int32_t main()
{
	freopen("tienphat.inp","r",stdin);
	freopen("tienphat.out","w",stdout);
	int n;
	cin >> n;
	vector <ii> a(n+1);
	vector <int> d(n+1);
	vector <vector<int>> f(n+1,vector<int>(n+1));
	for (int i=1;i<=n;i++) cin >> a[i].x >> a[i].c;
	sort(a.begin()+1,a.end()+1); 
	f[1][1]=a[1].c;	
	for (int i=2;i<=n;i++)
	{
		f[i][1]=f[i-1][1]+a[i].x-a[1].x;
		d[i]=f[i][1];
	}
	f[2][2]=a[1].c+a[2].c;
    d[1]=a[1].c;
    d[2]=min(f[2][1],f[2][2]);
	for (int i=3;i<=n;i++)
	{
		for (int j=2;j<i;j++)
		{
			f[i][j]=f[i-1][j]+a[i].x-a[j].x;
			d[i]=min(d[i],f[i][j]);
		}
		f[i][i]=d[i-1]+a[i].c;
		d[i]=min(d[i],f[i][i]);
	}
	cout << d[n];
}