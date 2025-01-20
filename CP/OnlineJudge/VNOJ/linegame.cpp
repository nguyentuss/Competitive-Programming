#include <bits/stdc++.h>

using namespace std;

long long  n ;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector <long long > v(n + 1);
	for (long long  i = 1 ; i <= n ; i++) 
		cin >> v[i];
	vector <vector<long long >> f(n + 1 , vector <long long > (2 , LLONG_MIN));
	f[1][1] = v[1];
	long long  maxplus , maxminus;
	maxplus = maxminus = LLONG_MIN;
	for (long long  i = 2 ; i <= n ; i++) {
		maxplus = max(maxplus , f[i - 1][1]);
		maxminus = max(maxminus , f[i - 1][0]);
		f[i][1] = max(f[i][1] , max(maxminus + v[i] , v[i]));
		f[i][0] = max(f[i][0] , maxplus - v[i]);
	}
	long long  ans = LLONG_MIN;
	for (long long  i = 1 ; i <= n; i++) {
		ans = max(ans , max(f[i][0] , f[i][1]));
	}
	cout << ans;
	return 0;
}