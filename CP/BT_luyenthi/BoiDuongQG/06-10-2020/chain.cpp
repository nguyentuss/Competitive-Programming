`#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){

	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("chain.inp","r",stdin);
	freopen("chain.out","w",stdout);
	int n ; cin >> n;
	int a[n];
	for (int i = 0 ; i < n ; i++)
		cin >> a[i];

	sort(a,a+n);
	int i = 0 , j = 0;
	while (n > 0){	
		if (a[i] >= n - j - 1 - i) {
			cout << n - (i+1);
			return 0;
		}
		else {
			j += a[i];
			i++;
		}
	}
	return 0;
}