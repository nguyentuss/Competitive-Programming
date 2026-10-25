#include <bits/stdc++.h>

using namespace std;

#define MAX_N (long long) (1e5 + 7)
#define inf (long long) (1e9 + 7)

vector <long long> v;
vector <long long> last(MAX_N , inf);
long long res[MAX_N];
long long n;

void revLIS() {
	for (long long i = 0 ; i < n; i++) {
		res[i] = lower_bound(last.begin() , last.end(), v[i]) - last.begin();
		last[res[i]] = min(last[res[i]] , v[i]);
	}
}
	
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (long long i = 1 ; i <= n ; i++) {
		long long x; cin >> x;
		v.push_back(x);
	}
	reverse(v.begin() , v.end());
	revLIS();
	long long ans = 0;
	for (long long i = 0 ; i < n ; i++) {
		ans = max(ans , res[i] + 1);
	}
	cout << ans;
	return 0;
}	