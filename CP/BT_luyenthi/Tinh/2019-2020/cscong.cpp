#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	//freopen("cscong.inp","r",stdin);
	//freopen("cscong.out","w",stdout);

	int n ; cin >> n;
	int a[n+1];
	int c[1001] = {1};
	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];

	for (int i = 1 ; i <= n ; i++)
		for (int j = i + 1 ; j <= n ; j++)
		{
			c[a[j] - a[i]] ++;
		}
	int s = c[1];
	for (int i = 2 ; i <= 1000 ; i ++)
	{
		if (a[i] != 1)
			s = max(s,c[i]);
	}
	cout << s;
	return 0;
}