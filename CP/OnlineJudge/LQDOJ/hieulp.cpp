#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

long long q;

long long POW(long long a , long long d , long long n) {
	if (d == 0) return 1;
	long long child = POW(a , d / 2 , n)%n;
	long long ans = (child%n*child%n)%n;
	if (d % 2 == 1) ans = (ans%n*a%n)%n;
	return ans%n;
}

bool calc(long long d , long long n) {
	long long a = 2 + rand()%(n - 4);
	long long x = POW(a , d , n);
	if (x == 1 || x == n - 1) return true;
	while (d != n - 1) {
		x = (x * x)%n;
		d *= 2;
		if (x == 1) return false;
		if (x == n - 1) return true;
	}
	return false;
}

bool millerrabin(long long a) {
	if (a == 1 || a == 4) return false;
	if (a <= 3) return true;

	long long d = a - 1;
	while (d % 2 == 0) {
		d /= 2;
	}
	int k = 50;
	for (int i = 0 ; i < k ; i++) {
		if (!calc(d , a)) return false;
	}
	return true;
}

bool check(long long n) {
	if (n == 1) return false;
	for (long long i = 2 ; i * i <= n ; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(){
	cin >> q;
	long long num1 , num2;
	for (int i = 1 ; i <= q ; i++) {
		cin >> num1;
		long long num2 = num1 - 1;
		long long s = num1*num1 + num1*num2 + num2*num2;
		if (check(s)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}