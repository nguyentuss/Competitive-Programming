#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize("Ofast")

#define MAX_VAL (int) (1e6 + 7)

int numerator[MAX_VAL] , denimator[MAX_VAL];
vector<int> eratosthenes(MAX_VAL);
vector <int> v;
vector<int> minPrime(MAX_VAL);

void init() {
	for (auto e : v) {
		numerator[e] = 0;
		denimator[e] = 0;
	}
}

void sieve() {
	eratosthenes[0] = true , eratosthenes[1] = true;
	for (int i = 2 ; i * i < MAX_VAL ;i++) {
		if (!eratosthenes[i]) {
			for (int j = i * i ; j < MAX_VAL ; j += i) {
				eratosthenes[j] = true;
				if (!minPrime[j]) {
					minPrime[j] = i;
				}
			}
		}
	}
	for (int i = 2 ; i < MAX_VAL ; i++) {
		if (!eratosthenes[i]) v.push_back(i);
		if (!minPrime[i]) minPrime[i] = i;
	}
}

void calctonumerator(int x) {
	while (x != 1) {
        numerator[minPrime[x]]++;
        x /= minPrime[x];
    }
}

void calctodenimator(int x) {
	while (x != 1) {
		denimator[minPrime[x]]++;
		x /= minPrime[x];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	int t; scanf("%d",&t);
	while (t--) {
		init();
		int n; scanf("%d",&n);
		for (int i = 1 ; i <= n ;i++) {
			int x; scanf("%d",&x);
			calctonumerator(x);
		}
		for (int i = 1 ; i <= n ; i++) {
			int x; scanf("%d",&x);
			calctodenimator(x);
		}
		for (auto e : v) {
			int subtract = min(numerator[e] , denimator[e]);
			numerator[e] -= subtract;
			denimator[e] -= subtract;
		}
		bool check = false;
		for (auto e : v) {
			if (denimator[e] && e != 2 && e != 5) {
				printf("repeating\n");
				check = true;
				break;
			}
		}
		if (!check) printf("finite\n");
	}
	//cerr << " \nTime: " <<  clock() / CLOCKS_PER_SEC << "ms";
	return 0;
}