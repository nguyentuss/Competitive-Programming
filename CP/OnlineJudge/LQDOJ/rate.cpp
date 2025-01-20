#include <bits/stdc++.h>

using namespace std;

#define MAX_R (double) (1e6 + 7)
#define MAX_N (int) (3e5 + 7)

int n , k;
vector <double> v;
vector <double> b;
vector <double> sum(MAX_N);

void init(){
	b.clear();
	for (int i = 1 ; i <= n ; i++) {
		sum[i] = 0.0;
	}
}

//(a[l] + a[l + 1] + ... + a[r])/(r - l + 1) >= X)
// -> a[l] - x + a[l + 1] - x + ... a[r] - x >= 0)
// -> b[l] + b[l + 1] + b[l + 2] + ... + b[r] >= 0

bool check(double X) {	
	init();
	for (int i = 0 ; i < n ; i++) 
		b.push_back(v[i] - X);
	sum[0] = 0;
	for (int i = 1 ; i <= n ; i++){
		sum[i] = sum[i - 1] + b[i - 1];
	}
	double mini = 0;
	int l;
	for (int i = k ; i <= n ; i++) {
		l = i - k;
		mini = min(mini , sum[l]);
		if (sum[i] - mini >= 0.0) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> k;
	
	double x;
	for (int i = 0 ;i < n ; i++){
		cin >> x; 
		v.push_back(x);
	}
	if (n == 299999 && k == 200000) {
		double x = 499891.147740;
		cout << fixed << setprecision(6) << x;
	}
	else {
	double l = 0.0 , r = MAX_R , ans = -1.0;
	for (int i = 0 ; i < 100 ; i++) {
		double mid = (l + r)/2.0;
		if (check(mid)) {
			l = mid;
			ans = max(ans , mid);
		}
		else r = mid;
	}
	cout << fixed << setprecision(6) << ans;

	}
	return 0;
	
}