#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long
const ll MAX_SIZE = 10000007;
#define mod (ll) (998244353)
#define f first
#define s second

vector<ll>minprime(MAX_SIZE);
vector<ll>prime;
vector<ll>SPF(MAX_SIZE);

ll POW(ll n , ll k) {
	if (k == 0) return 1;
	ll child = POW(n , k/2)%mod;
	if (k % 2 == 1) return (((child*child)%mod)*n%mod)%mod;
	else return ((child*child)%mod);
}

void sieve()
{
	for (int i = 2 ; i * i < MAX_SIZE ; i++) {
		if (minprime[i] == 0) {
			for (int j = i * i ; j < MAX_SIZE ; j+=i) {
				minprime[j] = i;
			}
		}
	}
	for (int i = 2 ; i < MAX_SIZE ; i++) 
		if (minprime[i] == 0) minprime[i] = i;
}

ll factorize(ll n) {
	ll res = 1 , d = 1;
	ll x = n;
	map<int ,int> m;
	while (n != 1) {
		m[minprime[n]]++;
		n /= minprime[n];
	}
	//for (auto e : v) cout << e << " ";
	int cnt = 0;
	for (auto it : m) {
		ll val = POW(it.f , it.s*(it.s + 1)/2);
		res = (POW(res , it.s + 1)*POW(val , d))%mod;
		d = (d*(it.s + 1))%mod;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		cout << factorize(x) << '\n';
	}
	return 0;
}