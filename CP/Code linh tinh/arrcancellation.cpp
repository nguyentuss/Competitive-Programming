#include <iostream>

using namespace std;

int main(){
	long long t , n  , x;

	cin >> t;

	while (t--){
		cin >> n; 
		long long  a[n];
		for (int i = 0;i<n;i++)	cin >> a[i];
		long long pos = 0;
		for (int i = 0;i<n;i++)
		{
			if (a[i] < 0) {
				x = pos + a[i];
				if (x>0){
					pos = x;
					a[i] = 0;
				}
				else {
					a[i] = a[i] + pos;
					pos = 0;
				}
			}
			else pos += a[i];
		}
		long long res = 0;
		for (int i = 0;i<n;i++) {
			if (a[i] < 0) res += (abs(a[i]));
		}
		cout << res << endl;
	}
}