#include <bits/stdc++.h>
using namespace std;
const long maxn = 1e6;

int res ,a[maxn];

int bn(int n , int x){

	int l = 1; int r = n;

	while (r >= l){
		int mid = (l + r) / 2;
		if (a[mid] == x) 
			return mid;
		if (a[mid] > x) {
			r = mid - 1;
		}
		if (a[mid] < x) {
			l = mid + 1;
		}
	}
	return -1;
}



int main(){

	int n,x; cin >> n >> x;

	for (int i = 1; i<=n; i++)
		cin >> a[i];
	res = bn(n,x);

	cout << res;
	return 0;
}