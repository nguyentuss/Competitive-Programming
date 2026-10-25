#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

long long t=0,n,k,mina=LLONG_MAX,res=0,c;
vector <long long> a(100),b(100);
bool ch=0;

void check()
{
	long long s=0;
	for (int i=0;i<n;i++) if (b[i]==1) s+=a[i];
	if (s==c) {cout << "YES";ch=1;return;}
}

void Try(long long i)
{
	for (int j=0;j<=1;j++)
	{
		b[i]=j;
		if (i==n-1) check();
		else Try(i+1);
	}
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("diacan.inp","r",stdin);
	freopen("diacan.out","w",stdout);
	cin >> n >> c;
	for (int i=0;i<n;i++) {cin >> a[i];t+=a[i];}
	Try(0);
	if (!ch) cout << "NO";
}