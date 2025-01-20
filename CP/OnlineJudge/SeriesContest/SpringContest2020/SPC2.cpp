#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector <ll> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		v.clear();
		int n; cin >> n;
		ll sum = 0;
		for (int i = 1 ; i <= n ;i++) {
			int x; cin >> x;
			v.push_back(x);
			sum += x;
		}
		sort(v.begin() , v.end());
		ll curr , ways , total ;
		curr = 0;
		total = sum , ways = 1LL*n;
		for (int i = 0 ; i < v.size() ; i++) {
			curr += v[i];
			total += sum;
			total -= 2*curr;
			total += (2*(i+1) - n)*v[i];
		}
		ll g = __gcd(total , ways);
		total /= g;
		ways /= g;
		cout << total << " " << ways << '\n';
	}
	return 0;
}