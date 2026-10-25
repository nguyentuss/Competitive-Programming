#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("bookstor.inp","r",stdin);
	freopen("bookstor.out","w",stdout);
	int n ; cin >> n;
	int a[n];
	for (int i = 1 ; i <= n ; i++)
		cin >> a[i] ;
	sort(a+1,a+n+1,greater<int>());
	long long s = 0;
	for (int i = 1 ; i <= n ; i++)
		if (i % 3 != 0) s += a[i];

	cout << s;

	return 0;

}