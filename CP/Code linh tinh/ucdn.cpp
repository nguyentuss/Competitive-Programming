#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	freopen("ucdn.inp","r",stdin);
	freopen("ucdn.out","w",stdout);
	int n ; cin >> n;
	int a[n+1];
	for (int i = 1 ;i <= n ;i ++) 
		cin >> a[i];
	int k , x , maxi = 0;
	for (int i = 1 ; i < n; i++){
		k = __gcd(a[i],a[i+1]);
		if (k!= 1)
			for (int j = i + 1 ; j <= n ;j ++){
				k = __gcd(k,a[j]);
				if (k == 1) break;
				else if (maxi < j - i + 1) maxi = j - i + 1;
			}
	}
	cout << maxi;
	return 0;

}