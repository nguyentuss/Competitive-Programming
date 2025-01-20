#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n , t ; cin >> n >> t;
	int a[n+5];
	long long s = 0 , dem = 0;
	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];
	int l = 1;
	for (int i = 1 ; i <= n ;i++){
		s += a[i];
		if (s<=t) dem++;
		if (s > t) {
			s -= a[l];
			l ++;
		}	
	}
	cout << dem ;
	return 0;
}