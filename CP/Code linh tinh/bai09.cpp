#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

	freopen("bai09.inp","r",stdin);
	freopen("bai09.out","w",stdout);
	

	int n; scanf("%d" , &n);

	vector<int> a(n+1);

	for (int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);

	vector<int> b(n+1,0);

	b[1] = 0;
	for (int i = 2 ; i <= n ; i++)
	{
		int dem = 0;
		for (int j = 1 ; j <=i ; j++)
			if (a[j] > a[i]) dem ++;
		b[i] = dem;
	}
			

	for (int i = 1 ; i <= n ; i++)
		printf("%d ",b[i]);
	
	

	return 0;
}