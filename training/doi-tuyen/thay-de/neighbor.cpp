#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e7 + 7)
#define int long long

vector<bool> isprime(MAX_N , true);
vector<int> v;
int n , k , a;

void eratosthenes() {
	isprime[1] = false;
	for (int i = 2 ; i * i < MAX_N ; i++) {
		if (isprime[i]) {
			for (int j = i*i ; j < MAX_N ; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 2 ; i < MAX_N ; i++) {
		if (isprime[i]) {
			v.push_back(i);
		}
	}
}

int calc(int pos) {
	for (int i = k - 1 ; i >= 0 ; i--) {
		if (v[i] % n == pos) {
			pos = 0;
		}
		else {
			pos = (pos + v[i]/(n - 1))%n;
			if (pos <= v[i]%(n - 1)) {
				pos = (pos + 1) % n;
			}
		}
	}
	return pos;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("neighbor.inp","r",stdin);
	freopen("neighbor.out","w",stdout);
	eratosthenes();
	//cout << v.size();
	cin >> n >> k >> a;
	int pos = a - 1;	
	for (int i = 0 ; i < k ; i++) {
		if (pos == 0) {
			pos = v[i] % n;
		}
		else {
			if (pos <= v[i] % (n - 1)) 
				pos = (pos - 1 + n) % n;
			//if (pos - v[i]/(n - 1) >= -n)
				pos = ((pos - v[i]/(n - 1))%n + n)%n;
		}
	}
	//cout << (pos + 1)%n << " " << (pos - 1 + n)%n << " ";
	cout << calc((pos + 1)%n) + 1 << " " << calc((pos - 1 + n)%n) + 1;
	return 0;
}