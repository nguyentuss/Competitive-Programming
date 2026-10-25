#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n , m;
queue <ll> q;
vector<ll> v;
vector<ll> res;

bool check(ll x) {
	for (ll i = 2 ; i * i <= x ;i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("snt.inp","r",stdin);
	freopen("snt.out","w",stdout);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> n >> m;
	q.push(2); q.push(3); q.push(5); q.push(7); 
	v.push_back(1); v.push_back(3); v.push_back(7); v.push_back(9);
	for (int x = 2 ; x <= 9 ; x++) {
		if (n <= x && x <= m && check(x)) 
			res.push_back(x);
	}
	while (q.empty() == false) {
		ll num = q.front();
		q.pop();
		for (int i = 0 ; i < (int) v.size() ; i++) {
			int x = v[i];
			int newnum = num*10 + x;
			if (newnum <= m) {
				if (check(newnum)) { 
					q.push(newnum);
					if (n <= newnum && newnum <= m) 
						res.push_back(newnum);
				}
			}
		}
	}
	for (int i = 0 ; i < (int) res.size() ; i++) cout << res[i] << '\n';

	return 0;
}