#include <bits/stdc++.h>

using namespace std;

#define MAX_N  (int) (4*1e6)

unsigned long long n , k;
vector <bool> sieve(MAX_N  + 1 , false);
vector <long long> v;

void solve() {
	for (long long i = 2 ; i * i <= 2800000  ; i++) {
		if (!sieve[i])
			for (long long j = i * i ; j <= 2800000; j += i) {
				sieve[j] = true;
			}
	}
	for (long long i = 2 ; i <= 2800000 ; i++) 
		if (!sieve[i]) v.push_back(i);
	return; 
}

unsigned long long calc(unsigned long long n , int k) {
	unsigned long long multi = 1;
	bool checked = true;
	for (int i = 0 ; i < k ; i ++) {
		if (multi > n/v[i]) {
			checked = false;
			break;
		}
		multi*= v[i];
	}
	int pos = 0;
	if (checked == false) cout << -1 << '\n'; 
	else {
		while (multi/v[pos] <= n/v[pos+k]) {
			multi/=v[pos];
			multi*=v[pos+k];
			pos++;
		}
		cout << multi << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	solve();
	int t; cin >> t;
	for (int i = 0 ; i < t ; i++) {
		cin >> n >> k;
		calc(n , k);
	}

	//for (int i = 0 ; i < 10 ; i++) cout << v[i] << " ";
	return 0;
}