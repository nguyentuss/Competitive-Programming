#include <bits/stdc++.h>

using namespace std;

unsigned long long q;

unsigned long long POW(unsigned long long a , unsigned long long d , unsigned long long n) {
	if (d == 0) return 1;
	unsigned long long child = POW(a , d / 2 , n)%n;
	unsigned long long ans = (child%n*child%n)%n;
	if (d % 2 == 1) ans = (ans%n*a%n)%n;
	return ans%n;
}

bool calc(unsigned long long d , unsigned long long n) {
	unsigned long long a = 2 ;
	unsigned long long x = POW(a , d , n);
	if (x == 1 || x == n - 1) return true;
	while (d != n - 1) {	
		x = (x * x)%n;
		d *= 2;
		if (x == 1) return false;
		if (x == n - 1) return true;
	}
	return false;
}

bool millerrabin(unsigned long long a) {
	if (a == 1 || a == 4) return false;
	if (a <= 3) return true;

	unsigned long long d = a - 1;
	while (d % 2 == 0) {
		d /= 2;
	}
	int k = 1;
	for (int i = 0 ; i < k ; i++) {
		if (!calc(d , a)) return false;
	}
	return true;
}

bool check(unsigned long long n) {
	if (n == 1) return false;
	for (unsigned long long i = 2 ; i * i <= n ; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> q;
	unsigned long long num1;
	for (int i = 1 ; i <= q ; i++) {
		cin >> num1;
		if (check(num1)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}