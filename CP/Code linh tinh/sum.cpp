#include <bits/stdc++.h>

using namespace std;
int n,i,j,t;

int main(){
	freopen("sum.inp","r",stdin);
	freopen("sum.out","w",stdout);

	cin >> n ;

	int a[(2*n)] = {0};
	for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				cin >>t;
				a[i-j+n] += t;
			}


	int ans = 0;

	for (i=1;i<=((2*n)-1);i++)
		ans = max(a[i],ans);
	cout << ans;

}