#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("chanbo.inp","r",stdin);
	freopen("chanbo.out","w",stdout);
	long long n,c;
	cin >> n >> c;
	vector <long long> a(n);
	for (auto &e:a) cin >> e;
	sort(a.begin(),a.end());
	long long l=a[0],r=a[n-1],res=0;
	while (l<=r)
	{
		long long mid=(l+r)/2,h=0,k=1,temp=1,d=1;
		bool check=0;
		while (temp<c&&d!=n)
		{
			if ((a[k]-a[h])>=mid) {temp++;h=k;k++;}
			else k++;
			d++;
		}
		if (temp==c) check=1;
		if (check)
		{
			l=mid+1;
			res=mid; 
		}	
		else r=mid-1;
	}
	cout << res;
}
