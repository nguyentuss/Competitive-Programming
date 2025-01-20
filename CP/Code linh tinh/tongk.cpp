#include <bits/stdc++.h>

using namespace std;

const long maxn = 1e7;
long a[maxn] , n , k , kq , s = 0 ;

int main(){

	freopen("tongk.inp","r",stdin);
	freopen("tongk.out","w",stdout);

	scanf("%ld%ld",&n,&k);

	for (long i = 1;i<=n;i++)
		scanf("%ld",&a[i]);
	for (long i = 1; i<=k;i++)
		s += a[i];
	kq = s;
	for (long i= k+1;i<=n;i++)
	{
		s += a[i];
		s -= a[i-k];
		if (s > kq) kq = s;
	}
	printf("%ld",kq);
	return 0;
}