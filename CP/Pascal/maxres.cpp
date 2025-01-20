#include <iostream>
#include <algorithm>
using namespace std;

int n , a[10000] , maxn = -1e9;

int check(int n){
	if (n == 1) return a[1];
	if (check(n-1)>a[n]) maxn = check(n-1);
	else maxn = a[n];
}

int main(){
	cin >> n;
	for (int i = 1 ;i <= n ; i++)
		cin >> a[i];
	check(n);

	cout << maxn;
	return 0;
}
